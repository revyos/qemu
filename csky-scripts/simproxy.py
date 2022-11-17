#!/usr/bin/env python
# -*- coding: gbk -*-

import commands
import os
import subprocess
import time
import re
from enum import Enum
import argparse

class ProcNode(object):
    def __init__(self, proc = None , status = None):
        self.proc = proc
        self.status = status

class Status(Enum):
        RECORD = 1

class SimProxy:
    def __init__(self, qemu, binary, ldpath, toolpath, cpf, port=13225):
        self.qemu = qemu
        self.binary = binary
        self.ldpath = ldpath
        self.toolpath = toolpath
        self.cpf = cpf
        self.port = port
        self.procdict = {}

    def __record(self):
        "Create record file"
        envparts = ' -E LD_DEBUG=all '
        traceparts = ' -csky-trace port=' + str(self.port) + ',proxy_trace=on '
        ldparts = ' -L ' + self.ldpath + ' '
        cmdline = self.qemu + envparts +  ldparts + traceparts + self.binary
        print(cmdline)

        os.system('rm ld.log')
        os.system('rm -rf trace')
        fout = open('ld.log', 'wb+')
        proc = subprocess.Popen(cmdline, shell=True, stdin=subprocess.PIPE, stdout=fout, stderr=fout)
        procnode = ProcNode(proc, Status.RECORD)
        self.procdict[self.binary] = procnode
        time.sleep(2)
        cmdline = self.cpf + ' record ' + '--port '+ str(self.port) + ' -e ' + self.binary
        print(cmdline)
        proc = subprocess.Popen(cmdline, shell=True, stdin=subprocess.PIPE)
        time.sleep(1)

    def __tar(self):
        elf = os.path.basename(self.binary)
        tar = elf + '.trace.' + time.strftime("%Y%m%d", time.localtime()) + '.tar.gz'
        cmdline = 'mkdir trace && mv *.asm trace/ && mv cpfdata/cpf.data trace/ && mv reloc.log trace/ && cp ' +  self.binary + ' trace/'
        os.system(cmdline)
        cmdline = 'tar -czvf ' + tar + ' '+ 'trace/*'
        print(cmdline)
        os.system(cmdline)
        cmdline = 'rm -rf trace'
        print(cmdline)
        os.system(cmdline)

    def __disas(self):
        "Disas shared libary and binary"
        fld = open('ld.log', 'rb')
        freloc = open('reloc.log', 'wb')
        libdict = {}
        libbasedict = {}
        libdict[os.path.basename(self.binary)] = self.binary

        dynlib = ''
        interp = ''
        for line in fld:
            if dynlib != '':
                libbasedict[dynlib] = re.match(r'.*dynamic.*base: (\S*).*size.*', line).group(1)
                dynlib = ''
                continue
            if 'needed by ' + self.binary in line:
                lib = re.match(r'.*file=(.*) \[.*;.*', line).group(1)
                libdict[lib] = 'NULL'
            elif 'trying file=' in line:
                path = re.match(r'.*trying file=(.*)$', line).group(1)
                pos = path.rfind('/')
                if pos == -1:
                    if path in libdict.keys():
                        libdict[path] = self.ldpath + path
                else:
                    lib = path[pos + 1:]
                    if lib in libdict.keys():
                        libdict[lib] = self.ldpath + path[1:]
            elif 'dynamically loaded by' in line:
                lib = re.match(r'.*file=(.*) \[.*;.*', line).group(1)
                libdict[lib] = lib
            elif 'generating link map' in line:
                dynlib = re.match(r'.*file=(.*) \[.*', line).group(1)
            elif 'proxy interp:' in line:
                pos = line.rfind('/')
                if pos == -1:
                    interp = line[len('proxy interp: ') : -1]
                else:
                    interp = line[pos + 1 : -1]
                libdict[interp] = line[len('proxy interp: '): -1]
            elif 'proxy interp addr:' in line:
                libbasedict[interp] = line[len('proxy interp addr: '): -1]

        for lib in libbasedict:
            pos = lib.rfind('/')
            if pos == -1:
                freloc.write(lib + ',' + libbasedict[lib] + '\n')
            else:
                freloc.write(lib[pos + 1:] + ',' + libbasedict[lib] + '\n')
        freloc.close()
        for lib in libdict:
            pos = lib.rfind('/')
            if pos == -1:
                fasm = lib + '.asm '
            else:
                fasm = lib[pos + 1:] + '.asm '
            cmdline = self.toolpath + 'riscv64-unknown-linux-gnu-objdump -d ' + libdict[lib] + ' > ' + fasm
            os.system(cmdline)
        del self.procdict[self.binary]
        self.__tar()

    status_map = {
        Status.RECORD : __disas,
    }

    def sim(self):
        self.__record()
        while len(self.procdict) > 0:
            time.sleep(10)
            for bench in self.procdict.keys():
                if self.procdict[bench].proc.poll() != None:
                    SimProxy.status_map[self.procdict[bench].status](self)

#if __name__ == '__main__':
#    simproxy = SimProxy(
#        '/lhome/software/liuzw/git/41/qemu/build/riscv64-linux-user/qemu-riscv64',
#        '/lhome/software/liuzw/git/Script/output/build/dhrystone/dhrystone',
#        '/home/liuzw/tools/rvlinux/sysroot/',
#        '/home/liuzw/tools/rvlinux/bin/',
#        '/lhome/software/liuzw/git/cpf/cpf64')
#    simproxy.sim()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Create trace and assemble ' \
                                     'files for Proxy')
    parser.add_argument('qemu', help='qemu binary')
    parser.add_argument('command', help='command line to run benchmark')
    parser.add_argument('ld', help='interpreter path')
    parser.add_argument('toolchain', help='toolchain path')
    parser.add_argument('cpf', help='cpf binary')
    args = parser.parse_args()
    simproxy = SimProxy(args.qemu, args.command, args.ld, args.toolchain, args.cpf)
    simproxy.sim()
