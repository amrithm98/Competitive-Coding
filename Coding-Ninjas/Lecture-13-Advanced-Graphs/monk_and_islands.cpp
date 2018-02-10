#include<bits/stdc++.h>
using namespace std;

int BFS(vector<vector<int>> graph,int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    int *level = new int[n+1];
    for(int i = 0; i <= n; i++)
        level[i] = 0;
    
    queue<int> q;
    q.push(0);

    visited[0] = true;
 
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < graph[v].size(); i++)
        {
            int next = graph[v][i];
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
                level[next] = level[v] + 1;
            }
        }

    }
    return level[n-1];
}

int main()
{
	
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> graph(n);

        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        int cost = BFS(graph,n);
        cout << cost << endl;
    }
	return 0;
}
