#!/bin/python

import sys

def currencies(n, x, s, f, m, A):
    maxVals=[]
    for i in range(n):
        maxVals+=[(i,max(A[i]),A[i].index(max(A[i])))]
    print(maxVals)
    for j in range(n):
        for i in range(k):
            

if __name__ == "__main__":
    n = int(raw_input().strip())
    x, s, f, m = raw_input().strip().split(' ')
    x, s, f, m = [int(x), int(s), int(f), int(m)]
    A = []
    for A_i in xrange(n):
        A_temp = map(float,raw_input().strip().split(' '))
        A.append(A_temp)
    currencies(n,x,s,f,m,A)
