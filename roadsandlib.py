#!/bin/python

import sys
from collections import defaultdict

def dfs(g,s):
    global sum,visited
    sum+=1
    visited[s]=True
    for i in (g.graph[s]):
        if visited[i]==False: 
            dfs(g,i)

class Graph:
    def __init__(self,V):
        self.vertices=V
        self.graph=defaultdict(list)
    def addEdge(self,a,b):
        self.graph[a].append(b)
        self.graph[b].append(a)
    def showGraph(self):
        return self.graph

q = int(raw_input().strip())
for a0 in xrange(q):
    visited=100010*[False]
    ans=0
    n, m, x, y = raw_input().strip().split(' ')
    n, m, x, y = [int(n), int(m), long(x), long(y)]
    g=Graph(n)
    for a1 in xrange(m):
        city_1, city_2 = raw_input().strip().split(' ')
        city_1, city_2 = [int(city_1), int(city_2)]
        g.addEdge(city_1,city_2)

    for i in range(1,n+1):
        if visited[i]==False:
            sum=0
            dfs(g,i)
            ans += min(x + y*(sum - 1), x*sum)
    print ans

    
        

    