#include <bits/stdc++.h>
using namespace std;

void BFS(int **graph,int start,bool *visited,int *level)
{
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        visited[v] = 1;
        cout << v << " ";
        for(int i = 0; i < 100; i++)
        {
            if(!visited[i] && graph[v][i])
            {
                visited[i] = true;
                q.push(i);
                level[i] = level[v] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,m;
        cin >> n;

        int **graph = new int*[100];
        for(int i = 0; i < 100; i++)
        {
            graph[i] = new int[100];
            for(int j = 0; j < 100; j++)
                graph[i][j] = 0;
        }
        
        for(int i = 0; i < 100; i++)
        {
            for(int j = 1; j <= 6 && i+j <= 99; j++)
            {
                graph[i][i+j] = 1;
            }
        }

        for(int i = 0; i < n; i++)
        {
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            for(int j = 0; j < 100; j++)
                graph[a][j] = 0;

            graph[a][b] = 1;
        }

        cin >> m;

        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            for(int j = 0; j < 100; j++)
                graph[a][j] = 0;
            graph[a][b] = 1;
        }

        // for(int i = 98; i < 100; i++)
        // {
        //     cout << i << " ";
        //     for(int j = 60; j < 100; j++)
        //         cout << graph[i][j] << " ";
        //     cout << endl;
        // }

        bool *visited = new bool[100];
        int *level = new int[100];

        for(int i = 0; i < 100; i++)
        {
            visited[i] = 0;
            level[i] = 0;
        }

        BFS(graph,0,visited,level);
        cout << level[99] - 1 << endl;
    }

    return 0;
}