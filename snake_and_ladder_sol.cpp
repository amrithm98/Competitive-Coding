#include <bits/stdc++.h>
using namespace std;

vector<int> *graph;

void BFS(int start,bool *visited,int *level)
{
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        visited[v] = 1;
        // cout << v << " ";
        for(int i = 0; i < graph[v].size(); i++)
        {
            int adj = graph[v][i];
            if(!visited[adj])
            {
                visited[adj] = true;
                q.push(adj);
                level[adj] = (level[v] + 1);
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

        graph = new vector<int>[100];
        for(int i = 0; i < 100; i++)
        {
            graph[i].clear();
        }
        
        for(int i = 0; i < 100; i++)
        {
            for(int j = 1; j <= 6 && i+j <= 99; j++)
            {
                graph[i].push_back(i+j);
            }
        }

        for(int i = 0; i < n; i++)
        {
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            graph[a].clear();
            for(int j = a-6; j < a; j++)
            {
                int a_pos = -1;
                for(int k = 0; k < graph[j].size() && j >= 0; k++)
                {
                    if(graph[j][k] == a)
                    {
                        a_pos = k;
                        break;
                    }
                }
                if(a_pos >= 0 && a_pos < graph[j].size())
                    graph[j][a_pos] = b;
            }
        }

        cin >> m;

        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            graph[a].clear();
            for(int j = a-6; j < a; j++)
            {
                int a_pos = -1;
                for(int k = 0; k < graph[j].size() && j >= 0; k++)
                {
                    if(graph[j][k] == a)
                    {
                        a_pos = k;
                        break;
                    }
                }
                if(a_pos >= 0 && a_pos < graph[j].size())
                    graph[j][a_pos] = b;
            }
        }

        // for(int i = 0; i < 100; i++)
        // {
        //     cout << i << " ";
        //     for(int j = 0; j < graph[i].size(); j++)
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

        BFS(0,visited,level);
        if(level[99] == 0)
            cout << -1 << endl;
        else
            cout << level[99]<< endl;
    }

    return 0;
}