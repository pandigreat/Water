#-*-coding:utf-8-*-#
import sys
import platform
import numpy as np

'''
	Read the xlxs file
'''
def ReadFile(fileName):
	print "ReadFile"
	sysstr = platform.system()
	dir = sys.path[0]
	dir = dir.split('\\')
	preStr = ""
	for i in dir:
		preStr += i + "\\\\"
	if(sysstr == "Windows"):
		fileName = preStr + fileName
	print "fileName is ", fileName
	ncols = 0
	nrows = 0
	#try:
	wb = load_workbook(fileName) #Import the workbook
	sheetname = wb.get_sheet_names() #Get the names of all sheetssheetname = wb.get_sheet_names() #Get the names of all sheets
	sheet = wb.get_sheet_by_name(sheetname[0]) #Get the sheet
	ncols = sheet.max_column
	nrows = sheet.max_row
	print "norows:", nrows
	
	Metrix = [[0 for col in range(ncols)] for row in range(nrows)]

	for r in range(1, nrows + 1):
		for c in range(1, ncols + 1):
			val = sheet.cell(row=r, column=c).value
			Metrix[r - 1][c - 1] = float(val)
	
	return (Metrix, nrows, ncols)
	
'''
	Record File
'''
def RecordResult(ResMetrix, nrows, rho, ResultFileName):
	print "RecordResult"
	w = Workbook()
	ws = w.create_sheet('Rho_Value_' + rho) #Insert a sheet from the head of the table
	for i in range(0, nrows):
		for j in range(0, nrows):
			ws.cell(row=i+1, column=j+1).value = ResMetrix [i][j]

	dir = sys.path[0]
	dir = dir.split('\\\\')
	preDir = ""
	for val in dir:
		preDir += val + '\\\\'
	sysstr = platform.system()
	if(sysstr == "Windows"):
		ResultFileName = preDir + ResultFileName
	
	w.save(ResultFileName)

'''
	Ralation coefficient calcalation
'''
def RalationCoefficent(idx, Metrix, nrows, ncols, rho):
	print 'RalationCoefficent...'
	metrix = [[0 for col in range(ncols)] for row in range(nrows)]
	li = []
	for i in range(nrows):
		if i is not idx:
			li.append(idx)
	
	Min = 999999999
	Max = -99999999
	
	for i in li:
		for j in range(ncols):
			val = abs(Metrix[idx][j] - Metrix[i][j])
			if val < Min:
				Min = val
			if val > Max:
				Max = val
	
	for i in range(nrows):
		for j in range(ncols):
			if (i == idx):
				ResMetrix[i][j] = 1
			else:
				ResMetrix[i][j] = (rho * Max + Min) / (rho * Max + Metrix[i][j])
	
	Res = []
	
	for i in range(nrows):
		sum = 0
		for j in range(ncols):
			sum += ResMetrix[i][j]
		Res.append(sum / ncols)
	
	return Res
'''
	Gray Ralation Analysis
'''
def GrayRaltionAnalysis(InputFileName, rho, ResultFileName = "GrayRaltion_Result"):
	print 'GrayRaltionAnalysis...'
	(Metrix, nrows, ncols) = ReadFile(InputFileName)
	AverageMetrix = []
	for i in range(nrows):
		ave = 0.0
		for val in Metrix[i]:
			ave += val
		AverageMetrix.append(ave / ncols)
	
	for i in range(nrows):
		ave = AverageMetrix[i]
		for j in range(ncols):
			Metrix[i][j] = Metrix[i][j] / ave
	
	ResMetrix = []
	
	RecordResult(Metrix, nrows, rho)
	print 'Done...'
	
	
if __name__ == '__main__':
	InputFileName = ""
	rho = 0.5 #Normally 0.5, below 0.5463 precisely
	GrayRaltionAnalysis(InputFileName, rho)
	