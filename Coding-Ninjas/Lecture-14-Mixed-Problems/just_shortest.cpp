#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1001];

vector<int> level(1001);

void bfs(int start,int num)
{
    queue<int> q;
    q.push(start);

    vector<bool> visited(num,false);
    visited[start] = true;

    while(!q.empty())
    {
        int n = q.front();
        q.pop();    

        for(int i = 0; i < graph[n].size(); i++)
        {
            int adj = graph[n][i];
            if(!visited[adj] && (level[adj] == -1) || (level[adj] > level[n]+1) )
            {
                visited[adj] = true;
                q.push(adj);

                if(level[adj] == -1)
                    level[adj] = level[n]+1;
                else
                    level[adj] = min(level[adj],level[n]+1);
            }
        }
    }
}

int main()
{
    //Write your code here

    ios_base::sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        graph[i].clear();

    for(int i = 2; i <= n; i++)
        level[i] = -1;

    level[1] = 0;

    while(m--)
    {
        int x;
        cin >> x;

        if(x == 1)
        {
            int v;
            cin >> v;
            cout << level[v] << endl;
        }
        else
        {
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            
            if(level[a] != -1)
                bfs(a,n+1);
        }
    }

    return 0;
}