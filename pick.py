#!/bin/python

import sys

n = int(raw_input().strip())
a = map(int,raw_input().strip().split(' '))
a.sort()
count=0
print(a)
for i in range(n-1):
    if abs(a[i]-a[i+1])<=1:
        count+=1
    else:
        count=0
print count
        