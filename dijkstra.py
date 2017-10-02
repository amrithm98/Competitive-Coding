from collections import defaultdict
from heapq import *

def dijkstra(edges, f, t):
    g = defaultdict(list)
    for l,r,c in edges:
        g[l].append((c,r))

    q, seen = [(0,f,())], set()
    while q:
        (cost,v1,path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = (v1, path)
            if v1 == t: return (cost, path)
            for c, v2 in g.get(v1, ()):
                if v2 not in seen:
                    heappush(q, (cost+c, v2, path))

    return float("inf")

if __name__ == "__main__":
    edges = [
        ("2","3",6),("1","3",6)
    ]
    
    print "=== Dijkstra ==="
    print edges
    print "A -> E:"
    print dijkstra(edges, "1", "2")
    print "F -> G:"
print dijkstra(edges, "1", "3")
print dijkstra(edges, "1", "4")