#include <bits/stdc++.h>
using namespace std;

void BFS(int **graph, int V,int start)
{
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    queue<int> que;

    int j;
    for(j = 0; j < V; j++)
    {
        // cout << "\nJ Value : " << j <<endl;
        if(!visited[j])
        {
            // cout << "\n BFS FROM " << j << endl;
            que.push(j);
            visited[j] = true;
            while(!que.empty())
            {
                int adj = que.front();
                que.pop();

                cout << adj << " ";

                for(int i = 0; i < V; i++)
                {
                    if(!visited[i] && graph[adj][i] == 1)
                    {
                        que.push(i);
                        visited[i] = true;
                    }
                }

            }
        }
    }
    

}

void DFS(int **graph,int V,int start,bool *visited)
{
    visited[start] = true;

    cout << start << " ";

    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && graph[start][i] == 1)
        {
            DFS(graph,V,i,visited);
        }
    }
}

void DFS_helper(int **graph,int V)
{
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            DFS(graph,V,i,visited);
        }
    }
    
}

int main()
{
    int V,E;
    cin >> V >> E;

    int **graph = new int*[V];
    for(int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for(int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < E; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    // for(int i = 0; i < V; i++)
    // {
    //     for(int j = 0; j < V; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "\nBFS: ";
    BFS(graph,V,0);
    cout << "\nDFS: ";
    DFS_helper(graph,V);

    return 0;
}