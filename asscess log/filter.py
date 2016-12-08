# -*- coding: UTF-8 -*-
import re
import sys 
import time
import xlrd
import xlwt

'''
	the function to filter the raw data
	delta the unit of time , the distance between the timestamp
	if delta is 1800, it means 1800 seconds
	InputFile means the name of file that contains the raw data
'''
def solve(delta, InputFile):
	dir = sys.path[0]
	dir_2 = dir.split('\\')
	fname = ""
	for i in range(len(dir_2)):
		fname += dir_2[i] + "\\\\"
	fnames = fname
	fnames += InputFile
	fp = open(fnames, 'r') #Open the file case.txt

	dictNum = {} #Record the appearance of the every api
	dict = {} #Record the response time and latency which is saved as a tuple of all service

	earlyTime = 9999999999 
	latestTime = 0 
	
	patternStr = r'%s(.+?)%s' %('\"','\"')
	APIPatten = re.compile(patternStr, re.IGNORECASE) #Get the pattern to find the url of apis
	patternStr = r'%s(.+?)%s' %('response_time:', ' ')
	ResponseTimePattern = re.compile(patternStr, re.IGNORECASE) #Get the pattern to find the ResponseTime Pattern
	patternStr = r'%s(.+?)%s' %(' - ', ']')
	TimeStampPattern = re.compile(patternStr, re.IGNORECASE) #Get the pattern to find the ResponseTime Pattern

	for line in fp:
		(i, j) = re.search(' - ', line).span()
		api = line[0: i] 
		post = re.search(APIPatten, line) 
		tmpPost = post.group(1)
		list = tmpPost.split(" ")
		api += list[1] #get the full name of url
		
		hasApi = False
		if dictNum.has_key(api):
			dictNum[api] += 1
			hasApi = True
		else:
			dictNum[api] = 0
		
		response_time = re.search(ResponseTimePattern, line)
		res_time = response_time.group(1)
		res_time = float(res_time) 
		time_stamp = re.search(TimeStampPattern, line)
		time_st = time_stamp.group(1)[1:].split(' ')
		time_st = time_st[0] #String like 30/08/2016:10:30:00.000
		time_st = time_st.split('.') #Split string into to two parts like string 30/08/2016:10:30:00 and string 000
		time_st_1 = time.strptime(time_st[0], '%d/%m/%Y:%H:%M:%S')
		time_st_2 = float(time_st[1]) * 0.001 #Set time into the unit second
		time_st_1 = time.mktime(time_st_1) + time_st_2 
		if time_st_1 < earlyTime:
			earlyTime = time_st_1
		if time_st_1 > latestTime:
			latestTime = time_st_1
		pass
		if hasApi is False:
			dict[api] = []
		dict[api].append((time_st_1, res_time)) 
	fp.close()	

	cntRes = {} #Result of respose time of all the apis
	cntThr = {} #Result of latency of all the apis
	msize = 0 #Max size of data
	'''
		Calculation of the throughoutput and response_time
		by the delta time
	'''

	for key in dict:
		dict[key].sort(key=lambda x:x[0]) #Sort the data of all apis according to the timestamps  
		startTime = int(earlyTime)
		endTime = int(startTime + delta)  
		cntRes[key] = []
		cntThr[key] = []
		i = 0
		l = len(dict[key])  
		cnt = 0
		ans_res = 0  
		pass
		while(i < l and startTime <= latestTime):
			(time_st, res_time) = dict[key][i]
			pass
			if(startTime <= time_st and time_st <= endTime): 
				cnt += 1
				ans_res += res_time
				i += 1
				pass
			else:
				cntThr[key].append(cnt)
				if cnt is 0:
					cntRes[key].append(ans_res)
				else:
					cntRes[key].append(ans_res / (1.0 * cnt))
				pass	
				cnt = 0
				ans_res = 0
				startTime += delta
				endTime += delta
			pass
		cntThr[key].append(cnt)
		if cnt > 0:
			cntRes[key].append(ans_res / (1.0) * cnt)
		else :
			cntRes[key].append(ans_res)
		if msize < len(cntThr[key]):
			msize = len(cntThr[key])

	'''
		Fill up the sheet
	'''
	for key in cntThr:
		l = len(cntThr[key])
		d = msize - l
		while(d > 0):
			cntThr[key].append(0)
			d = d - 1
	for key in cntRes:
		l = len(cntRes[key])
		d = msize - l
		while(d > 0):
			cntRes[key].append(0.0)
			d = d - 1
			
	'''
		Write result to file named result.xls 
		Result of calculation of response time is stored as a sheet named res_time
		Result of calculation of throughoutput is stored as a sheet named throughoutput
	''' 
	w = xlwt.Workbook()
	ws = w.add_sheet('res_time')
	i = 0
	j = 0
	for key in cntRes:
		ws.write(i, j, key)
		j += 1
		for val in cntRes[key]:
			ws.write(i, j, val)
			j += 1
		i += 1
		j = 0
	ws2 = w.add_sheet('throughoutput')
	i = 0
	j = 0
	for key in cntThr:
		ws2.write(i, j, key)
		j += 1
		for val in cntThr[key]:
			ws2.write(i, j, val)
			j += 1
		i += 1
		j = 0
	w.save(fname + 'result.xls')
	print 'All done...'
	
if __name__ == '__main__':
	InputFile = "case.txt"
	delta = 1800
	solve(delta, InputFile)

	
	
