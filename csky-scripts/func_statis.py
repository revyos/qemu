#!/usr/bin/python
#-*- coding:utf-8 -*-

from sys import argv
import subprocess
import string

_, log_file, elf_file = argv

#print("log_file ", log_file)
#print("elf_file ", elf_file)

tb_map = [[0, 0, 0, 0]]
tb_tmp = []
gp = subprocess.Popen(["grep", "tb_map", log_file], stdout=subprocess.PIPE)
for line in gp.stdout.readlines():
	_, tb_start, tb_end, inst_num = line.split()
	if not int(tb_start, 16) in tb_tmp:
		tb_map.append([int(tb_start, 16), int(tb_end, 16), int(inst_num), 0])
		tb_tmp.append(int(tb_start, 16))
#	print(tb_start, tb_end, inst_num)
#print(sorted(tb_map))

sed = subprocess.Popen(["sed", "/tb_map/d", log_file], stdout=subprocess.PIPE)
sort = subprocess.Popen(["sort"], stdin=sed.stdout, stdout=subprocess.PIPE)
uniq = subprocess.Popen(["uniq", "-c"], stdin=sort.stdout, stdout=subprocess.PIPE)

pc_map = [[0, 0]]
for line in uniq.stdout.readlines():
	num, hex_num = line.split()
	pc_map.append([int(hex_num, 16), int(num)])
#	print(int(num), hex(int(hex_num, 16)))
#print(pc_map)

for tb in tb_map:
	for pc in pc_map:
		if tb[0] == pc[0]:
			tb[3] = tb[2] * pc[1]

#print(sorted(tb_map))

readelf = subprocess.Popen(["readelf", "-s", elf_file], stdout=subprocess.PIPE)
gp = subprocess.Popen(["grep", "FUNC"], stdin=readelf.stdout, stdout=subprocess.PIPE)

func_map = [[0,0,0,0]]
for line in gp.stdout.readlines():
	try:
		Num,Value,Size,Type,Bind,Vis,Ndx,Name = line.split()
		func_map.append([int(Value, 16), int(Value, 16) + int(Size), Name, 0])
	except:
		print("\n\nWARNING: an empty FUNC name\n\n")

func_map = sorted(func_map)
#print(func_map)

for func in func_map:
	for tb in tb_map:
		if (tb[0] >= func[0]) and (tb[1] <= func[1]):
			func[3] += tb[3]

biger = 0
for i in func_map:
	if i[3] != 0 and i[0] > biger:
		biger = i[0]
		print(i[2], hex(i[0]), hex(i[1]), i[3])
