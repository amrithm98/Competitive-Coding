#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int start;
    int end;
    int weight;
};

struct DisjSet
{
    int parent;
    int rank;
};

int find(DisjSet *ds, int x)
{
    if(ds[x].parent != x)
        ds[x].parent = find(ds,ds[x].parent);

    return ds[x].parent;
}

void Union(DisjSet *ds, int x, int y)
{
    int rootX = find(ds,x);
    int rootY = find(ds,y);

    if(ds[rootX].rank < ds[rootY].rank)
    {
        ds[rootX].parent = rootY;
    }
    else if(ds[rootX].rank > ds[rootY].rank)
    {
        ds[rootY].parent = rootX;
    }
    else
    {
        ds[rootX].parent = rootY;
        ds[rootY].rank++;
    }
}

bool isUnion(DisjSet *ds, int x, int y)
{
    return find(ds,x) == find(ds,y);
}

pair<int,int> costOfAirports(Edge *graph, DisjSet *ds, int cost, int n, int m)
{
    int totalCost = 0;
    int airCount = 0;

    int j = 0;

    for(int i = 0; i < m &&  j < n-1 && graph[i].weight < cost; i++)
    {
        if(!isUnion(ds,graph[i].start,graph[i].end))
        {
            totalCost += graph[i].weight;
            Union(ds, graph[i].start, graph[i].end);
            j++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(ds[i].parent == i)
        {
            totalCost += cost;
            airCount++;
        }
    }
    return make_pair(totalCost,airCount);
}

bool compare(Edge a,Edge b)
{
    return a.weight < b.weight;
}

int main()
{
    int t;
    cin >> t;
    
    int k = 1;
    while(k <= t)
    {
        int n,m,cost;
        cin >> n >> m >> cost;

        Edge *graph = new Edge[m];
        for(int i = 0; i < m; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            graph[i] = {a-1,b-1,c};
        }

        DisjSet *ds = new DisjSet[n];

        for(int i = 0; i < n; i++)
        {
            ds[i].parent = i;
            ds[i].rank = 0;
        }

        sort(graph, graph + m, compare);

        pair<int,int> ans = costOfAirports(graph,ds,cost,n,m);

        cout <<  "Case #" << k << ": " << ans.first << " " << ans.second << endl;

        k++;
    }
}