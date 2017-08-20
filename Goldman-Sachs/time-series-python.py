#!/bin/python
import sys

def query_1(t,p,n,v):
    val=0
    for i in range(n):
        if(p[i]>=v):
            val=t[i]
            break
    if(val==0):
        return -1
    else:    
        return val

def query_2(t,p,n,v):
    val=0
    i=0
    for i in range(n):
        if(t[i]>=v):
            pos=i
            break

    maxVal=-1
    for j in range(pos,n):
        if(p[j]>maxVal):
            maxVal=p[j]
    if(maxVal==0):
        return -1
    else:    
        return maxVal

if __name__ == "__main__":
    n, q = raw_input().strip().split(' ')
    n, q = [int(n), int(q)]
    t = map(int, raw_input().strip().split(' '))
    p = map(int, raw_input().strip().split(' '))
    for a0 in xrange(q):
        _type, v = raw_input().strip().split(' ')
        _type, v = [int(_type), int(v)]
        if _type==1:
            result=query_1(t,p,n,v)
            print(result)
        else:
            result=query_2(t,p,n,v)
            print(result)

