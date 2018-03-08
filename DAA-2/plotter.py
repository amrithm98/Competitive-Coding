import matplotlib.pyplot as plt

plot1 = []
plot2 = []
with open("output1.txt") as f:
    for line in f:
        plot1 += [list(map(int,line.split()))]

with open("output2.txt") as f:
    for line in f:
        plot2 += [list(map(int,line.split()))]

plot1.sort(key = lambda x : x[0])
plot2.sort(key = lambda x : x[0])

x_val = [x[0] for x in plot1]
y1 = [x[1] for x in plot1]
y2 = [x[1] for x in plot2]

print("X",x_val)
print("DFS",y1)
print("DSU",y2)

plt.title('Connected Components Using DFS & Union-Find')
plt.xlabel('V + E')
plt.ylabel('Number of Steps T(V+E)')
plt.plot(x_val,y1)
plt.plot(x_val,y2)

plt.legend(['DFS = 1', 'Union-Find = 2'], loc='upper left')

plt.show()