import math
import os
'''
	无聊的加密算法
	其实就是把一段英文文字映射到1~9
	参见九宫格中文输入法
'''

def AlphaToDigits(x):
	#ord() chr()
	res = ""
	for i in range(len(x)):	
		if(ord(x[i]) <= ord('r') and ord(x[i]) >= ord('a')): 
			v = chr((ord(x[i]) - ord('a')) / 3 + 1 + ord('0'))
			res += v
		elif(x[i] <= 'R' and x[i] >= 'A'):
			v = chr((ord(x[i]) - ord('A')) / 3 + 1 + ord('0'))  
			res += v
		elif(x[i] == 'S' or x[i] == 's'):
			res += "7"
		elif(x[i] >= 't' and x[i] <= 'y'):
			res += chr((ord(x[i]) - ord('a')) / 3 + 1 + ord('0'))
		elif(x[i] >= 'T' and x[i] <= 'Y'):
			res += chr((ord(x[i]) - ord('A')) / 3 + 1 + ord('0'))
		elif(x[i] == 'Z' or x[i] == 'z'):
			res += '9'
			
	return res
				
x = raw_input("the key: ")
x = AlphaToDigits(x)
print x
