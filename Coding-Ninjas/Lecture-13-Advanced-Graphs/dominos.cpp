#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];

void DFS(int start,stack<int> &finishedStack, bool *visited)
{
    visited[start] = true;
    for(int i = 0; i < graph[start].size(); i++)
    {
        int adj = graph[start][i];

        if(!visited[adj])
        {
            DFS(adj,finishedStack,visited);
        }
    }

    finishedStack.push(start);
}

void DFSRev(int start,unordered_set<int> &visitSet)
{
    visitSet.insert(start);

    for(int i = 0; i < graph[start].size(); i++)
    {
        int adj = graph[start][i];

        if(visitSet.count(adj) == 0)
        {
            DFSRev(adj,visitSet);
        }
    }
}

void getSCC(int n)
{
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++)
        visited[i] = false;
    
    stack<int> finishedStack;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            DFS(i,finishedStack,visited);
        }
    }

    unordered_set<int> visitSet;
    int count = 0;
    while(visitSet.size() < n)
    {
        int t = finishedStack.top();
        finishedStack.pop();

        if(visitSet.count(t) == 0)
        {
            DFSRev(t,visitSet);
            count++;
        }
    }
    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,m;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
        {
            graph[i].clear();
        }

        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;

            graph[a-1].push_back(b-1);
        }

        getSCC(n);
    }

    return 0;
}