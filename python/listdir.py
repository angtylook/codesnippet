#! /usr/bin/python
import os
import sys

def displayDir(dir):
    for i in os.listdir(dir):
	file = os.path.join(dir,i)
	if os.path.isdir(file):
	    displayDir(file)
	else:
	    print file

def displayDir2(dir):
    yid = os.walk(dir)
    for rootDir,pathList,fileList in yid:
	for file in fileList:
	    print os.path.join(rootDir,file)

if len(sys.argv) > 1:
    displayDir(sys.argv[1])

#displayDir("/Users/z/unixmacos/")
#displayDir2("/Users/z/Music/")

