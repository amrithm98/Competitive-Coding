#include <bits/stdc++.h>
using namespace std;


int flag = 0;

void DFS(vector<unordered_set<int>> &graph,int n,vector<int> &perms,int &i,vector<bool> &visited)
{
    if(i == n-1)
        return;
    visited[perms[i]] = 1;
    if(!visited[perms[i+1]] && graph[perms[i]].find(perms[i+1]) != graph[perms[i]].end())
    {
        i += 1;
        DFS(graph,n,perms,i,visited);
    }
    else
    {
        flag = 1;
        return;
    }
}


string permPos(vector<unordered_set<int>> &graph,vector<int> &perms,int n)
{
    vector<bool> visited(n,0);
    int i = 0;
    DFS(graph,n,perms,i,visited);
    if(flag)
        return "NO";
    else
        return "YES";
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,m;
        cin >> n >> m;
        flag = 0;

        vector<unordered_set<int>> graph(n+1);
        
        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;

            graph[a].insert(b);
            graph[b].insert(a);
        }

        vector<int> perms(n);
        for(int i = 0; i < n; i++)
            cin >> perms[i];

        cout << permPos(graph,perms,n) << endl;
    }

    return 0;
}