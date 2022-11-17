#!/usr/bin/python
#-*- coding:utf-8 -*-

from sys import argv
import subprocess
import string
import argparse
import os.path
import sys

FLAGS = None

def sorted_tb_print(tb_map, total_insn):
	sorted_tb = sorted(tb_map)
	for tb in sorted_tb:
		tb_percent = tb[3] * 100.0 / total_insn
		if tb_percent > FLAGS.tb_limit:
			print("%2.2f" % tb_percent, hex(tb[0]), hex(tb[1]), tb[2], tb[3])
	

def main():
	log_file = FLAGS.log_file
	elf_file = FLAGS.elf_file

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
	
	total_insn = 0
	for tb in tb_map:
		for pc in pc_map:
			if tb[0] == pc[0]:
				tb[3] = tb[2] * pc[1]
				total_insn = total_insn + tb[3]
	
	#print(sorted(tb_map))
	if FLAGS.show_tb:
		sorted_tb_print(tb_map, total_insn)
		return

	#elf func_map
	readelf = subprocess.Popen(["readelf", "-s", elf_file], stdout=subprocess.PIPE)
	gp = subprocess.Popen(["grep", "FUNC"], stdin=readelf.stdout, stdout=subprocess.PIPE)
	
	func_map = [[0,0,0,0]]
	for line in gp.stdout.readlines():
		try:
			Num,Value,Size,Type,Bind,Vis,Ndx,Name = line.split()
			func_map.append([int(Value, 16), int(Value, 16) + int(Size), Name, 0])
		except:
			print("\n\nWARNING: skip a func\n\n", line)
	
	#func_map = sorted(func_map)
	#print(func_map)

	#so func_map
	so_list = zip(FLAGS.so_list[0::2], FLAGS.so_list[1::2])
	for so_addr in so_list:
		#print(so_addr)
		readelf = subprocess.Popen(["readelf", "-s", so_addr[0]], stdout=subprocess.PIPE)
		gp = subprocess.Popen(["grep", "FUNC"], stdin=readelf.stdout, stdout=subprocess.PIPE)
		
		so_func_map = [[0,0,0,0]]
		for line in gp.stdout.readlines():
			try:
				Num,Value,Size,Type,Bind,Vis,Ndx,Name = line.split()
				so_func_map.append([int(Value, 16) + int(so_addr[1], 16), int(Value, 16) + int(Size) + int(so_addr[1], 16), Name, 0])
			except:
				print("\n\nWARNING: skip a FUNC\n\n", line)

		func_map = func_map + so_func_map

	func_maps = sorted(func_map, key=lambda x:x[0])

	for func in func_maps:
		for tb in tb_map:
			if (tb[0] >= func[0]) and (tb[1] <= func[1]):
				func[3] += tb[3]

	biger = 0
	print("total instructions: ", total_insn)
	for i in func_maps:
		if i[3] != 0 and i[0] > biger:
			biger = i[0]
			insn_percent = i[3] * 100.0 / total_insn
			if FLAGS.limit < insn_percent: 
				print("%2.2f" % insn_percent, i[2], hex(i[0]), hex(i[1]), i[3])


if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument(
		'--elf_file',
		type=str,
		default='',
		help="Which elf had run.")
	parser.add_argument(
		'--log_file',
		type=str,
		default='./t.log',
		help="Where the tb_trace log is.")
	parser.add_argument(
		'--so_list',
		type=str,
		nargs="+",
		help='List all dynamic library and load address')
	parser.add_argument(
		'--limit',
		type=float,
		default=0.001,
		help="How much of limit.")
	parser.add_argument(
		'--show_tb',
		type=bool,
		default=False,
		help="Show tb to replace functions.")
	parser.add_argument(
		'--tb_limit',
		type=float,
		default=0.01,
		help="How much of tb limit.")
	FLAGS, unparsed = parser.parse_known_args()
	main()

