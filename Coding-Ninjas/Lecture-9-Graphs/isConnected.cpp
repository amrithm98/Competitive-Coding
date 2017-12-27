#include<bits/stdc++.h>
using namespace std;

void DFS(int **graph,int n,int sv,int *visited)
{
    visited[sv] = true;
    
    for(int i = 0; i < n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(graph[sv][i] == 1)
        {
            if(visited[i])
            {
                continue;
            }
            else
            {
                DFS(graph,n,i,visited);
            }
        }
    }
}

void dfs_disconnected(int **graph,int n)
{
    int *visited = new int[n];
    memset(visited,0,sizeof(visited));

    //Run DFS on One vertex & see if something is unvisited
    DFS(graph,n,0,visited);

    bool disc = false;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            disc = true;
            break;
        }
    }

    delete [] visited;

    if(disc)
        cout<<"false"<<endl;
    else
        cout<<"true"<<endl;
}

int main()
{
    int n,e;
    cin >> n >> e;
    int **graph = new int*[n];
    for(int i = 0;i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }

    dfs_disconnected(graph,n);

    for(int i = 0;i < n; i++)
    {
        delete [] graph[i];
    }
    delete [] graph;

    return 0;
}