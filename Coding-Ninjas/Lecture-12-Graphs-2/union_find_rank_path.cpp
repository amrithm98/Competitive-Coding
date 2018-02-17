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

bool compare(Edge a,Edge b)
{
    return a.weight < b.weight;
}

int find(DisjSet *ds,int val)
{
    if(ds[val].parent != val)
    {
        ds[val].parent = find(ds,ds[val].parent);
    }
    return ds[val].parent;
}

void Union(DisjSet *ds,int x,int y)
{
    int rootX = find(ds,x);
    int rootY = find(ds,y);

    if(ds[rootX].rank  < ds[rootY].rank)
    {
        ds[rootX].parent = rootY;
    }
    else if(ds[rootX].rank  > ds[rootY].rank)
    {
        ds[rootY].parent = rootX;
    }
    else
    {
        ds[rootX].parent = rootY;
        ds[rootY].rank++;
    }
}

bool hasCycle(Edge *graph, DisjSet *ds,int n,int m)
{
    sort(graph, graph + m,compare);

    for(int i = 0; i < m; i++)
    {
        int x = find(ds,graph[i].start);
        int y = find(ds,graph[i].end);

        if(x == y)
            return true;
        
        Union(ds,x,y);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;

    Edge *graph = new Edge[m];
    
    DisjSet *ds = new DisjSet[n];

    for(int i = 0; i < n; i++)
    {
        ds[i].parent = i;
        ds[i].rank = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;

        graph[i] = {a,b,c};
    }

    cout << "\nThe Graph Has Cycle: " << hasCycle(graph,ds,n,m) << endl;
}