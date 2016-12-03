# -*- coding: UTF-8 -*-
import re
import os
import sys

dir = sys.path[0]
dir_2 = dir.split('\\')
fname=""
for i in range(len(dir_2)):
	fname += dir_2[i] + "\\\\"
fname += "case.txt"
fp = open(fname, 'r') 

patternStr = r'%s(.+?)%s' %('\"','\"')
APIPatten = re.compile(patternStr, re.IGNORECASE) #Get the pattern to find the url of apis
patternStr = r'%s(.+?)%s' %('response_time:', ' ')
ResponseTimePattern = re.compile(patternStr, re.IGNORECASE) #Get the pattern to find the ResponseTime Pattern

for line in fp:
	(i, j) = re.search(' - ', line).span()
	api = line[0: i] 
	post = re.search(APIPatten, line) 
	tmpPost = post.group(1)
	list = tmpPost.split(" ")
	api += list[1] #get the full url
	response_time = re.search(ResponseTimePattern, line)
	res_time = response_time.group(1)
	res_time = float(res_time)
	
