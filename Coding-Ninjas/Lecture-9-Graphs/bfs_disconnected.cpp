#include <bits/stdc++.h>
using namespace std;

void BFS(int **graph,int n,int sv,int *visited)
{
    queue<int> que;
    que.push(sv);
    visited[sv] = 1;

    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        cout<<v<<" ";

        for(int i = 0; i < n; i++)
        {
            if(i == sv)
            {
                continue;
            }
            
            if(graph[v][i] == 1 && !visited[i]) 
            {
                visited[i] = 1;
                que.push(i);
            }

        }
    }
}

void bfs_disconnected(int **graph,int n)
{
    int *visited = new int[n];
    memset(visited,0,sizeof(visited));

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            BFS(graph,n,i,visited);
        }
    }

    delete [] visited;
}


int main() {
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

    bfs_disconnected(graph,n);

    return 0;
}
