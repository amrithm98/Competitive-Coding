#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int start;
    int end;
    int weight;
};

int findParent(int v,int *parent)
{
    if(parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v],parent);
}


bool isSafe(int *parent,Edge e)
{
    int p1,p2,v1,v2;
    v1 = e.start;
    v2 = e.end;
    p1 = findParent(v1,parent);
    p2 = findParent(v2,parent);
    
    return !(p1 == p2);
}

bool compare(Edge a,Edge b)
{
    return a.weight < b.weight;
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  Edge *edges = new Edge[E];
  Edge *mst = new Edge[V-1];

  for(int i = 0; i < E; i++)
  {
      int a,b,c;
      cin >> a >> b >> c;
      edges[i] = {a,b,c};
  }
  
  sort(edges,edges+E,compare);

  int count = 0;
  int *parent = new int[V];

  for(int i = 0; i < V; i++)
    parent[i] = i;

  int i = 0;
  while( count < V-1)
  {
      if(isSafe(parent,edges[i]))
      {
          mst[count++] = edges[i];
          parent[edges[i].end] = edges[i].start;
      }
      i++;
  }

  for(int i = 0; i < count ; i++)
  {
      int f,s;

      if(mst[i].start < mst[i].end)
      {
            f = mst[i].start;
            s = mst[i].end;
      }
      else
      {
          s = mst[i].start;
          f = mst[i].end;
      }
      cout << f << " " << s << " " << mst[i].weight << endl;
  }

  return 0;
}
