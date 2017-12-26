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
            if(graph[v][i] == 1 && !visited[i]) 
            {
                visited[i] = 1;
                que.push(i);
            }

        }
    }
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

    int *visited = new int[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    BFS(graph,n,0,visited);

    return 0;
}
