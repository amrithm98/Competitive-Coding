#!/bin/python

import sys


arr = []
for arr_i in xrange(6):
    arr_temp = map(int,raw_input().strip().split(' '))
    arr.append(arr_temp)
hrGlass=[]
for arr_i in xrange(4):
    arr_temp = [0,0,0,0]
    hrGlass.append(arr_temp)
for i in range(0,4):
	for j in range(0,4):
        	hrGlass[i][j]=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2] 
#print hrGlass
maxSum=hrGlass[0][0]
for i in range(0,4):
	for j in range(0,4):
		if(hrGlass[i][j]>maxSum):
			maxSum=hrGlass[i][j]
print maxSum

