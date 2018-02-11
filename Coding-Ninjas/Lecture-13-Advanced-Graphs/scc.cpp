#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
vector<int> graphT[100001];
vector<vector<int>> components;

void DFS(int n, int start, stack<int> &finishedStack, unordered_set<int> &visited)
{
    visited.insert(start);
    for(int i = 0; i < graph[start].size(); i++)
    {
        int adj = graph[start][i];

        if(visited.count(adj) == 0)
        {
            DFS(n,adj,finishedStack,visited);
        }
    }
    finishedStack.push(start);
}

void DFS2(int n, int start, vector<int> &comp, unordered_set<int> &visited)
{
    visited.insert(start);
    comp.push_back(start);
    for(int i = 0; i < graphT[start].size() ; i++)
    {
        int adj = graphT[start][i];
        if(visited.count(adj) == 0)
        {
            DFS2(n,adj,comp,visited);
        }
    }
}

void getSCC(int n)
{
    unordered_set<int> visited;
    stack<int> finishedStack;
    for(int i = 0; i < n; i++)
    {
        if(visited.count(i) == 0)
        {
            DFS(n,i,finishedStack,visited);
        }
    }

    visited.clear();

    while(!finishedStack.empty())
    {
        int adj = finishedStack.top();
        finishedStack.pop();
        if(visited.count(adj) != 0)
        {
            continue;
        }

        vector<int> comp;
        DFS2(n,adj,comp,visited);
        components.push_back(comp);
    }
}

void printSCC()
{
    cout << endl;
    for(int i = 0; i < components.size(); i++)
    {
        for(int j = 0; j < components[i].size(); j++)
        {
            cout << components[i][j]+1 << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        graph[i].clear();
        graphT[i].clear();
    }

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graphT[b-1].push_back(a-1);
    }

    getSCC(n);
    printSCC();

    return 0;
}