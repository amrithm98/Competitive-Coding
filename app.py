#!/bin/python

import sys
s,t = raw_input().strip().split(' ')
s,t = [int(s),int(t)]
a,b = raw_input().strip().split(' ')
a,b = [int(a),int(b)]
m,n = raw_input().strip().split(' ')
m,n = [int(m),int(n)]
apple = map(int,raw_input().strip().split(' '))
orange = map(int,raw_input().strip().split(' '))
app_count=0
org_count=0
for i in apple:
	dist=0
	if i>=0:
		dist=a+i
		print(dist)
		if(dist>=s and dist<=t):
			app_count+=1
for i in orange:
	dist=0
	if i<=0:
		dist=b+i
		print(dist)
		if(disdist<=t and dist>=s):
		      org_count+=1
print(app_count)
print(org_count)


