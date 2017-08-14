import collections

class Queue:
    def __init__(self):
        self.elements = collections.deque()
    
    def empty(self):
        return len(self.elements) == 0
    
    def put(self, x):
        self.elements.append(x)
    
    def get(self):
        return self.elements.popleft()

class SimpleGraph:
    def __init__(self):
        self.edges = {}
    
    def neighbors(self, id):
        return self.edges[id]

class Graph:
	def __init__(self):
		self.graph=[]
	def neighbors(self,id):
		return self.graph[id]

def breadth_first_search_1(graph, start):
    # print out what we find
    frontier = Queue()
    frontier.put(start)
    visited = {}
    visited[start] = True
    while not frontier.empty():
        current = frontier.get()
        print("Visiting %r" % current)
        neighbors=graph.neighbors(current)
        for i in range(0,len(neighbors)):
        	next=neighbors[i]
	        if next==1:
	        	if i not in visited:
		            frontier.put(i)
		            visited[i] = True


# example_graph = SimpleGraph()

# example_graph.edges = {
#     '1': ['2'],
#     '2': ['1', '3', '4'],
#     '3': ['1'],
#     '4': ['5', '1'],
#     '5': ['2']
# }
Matgraph=Graph()

Matgraph.graph=[[0,1,0,0,0],
		[1,0,1,1,0],
		[1,0,0,0,0],
		[1,0,0,0,1],
		[0,1,0,0,0]]

#print (Matgraph.neighbors(1))
breadth_first_search_1(Matgraph,0)
