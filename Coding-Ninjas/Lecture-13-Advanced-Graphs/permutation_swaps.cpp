#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
vector<vector<int>> components;

void DFS(int n, vector<int> &comp,int start,bool *visited)
{
    visited[start] = true;
    comp.push_back(start);

    for(int i = 0; i < graph[start].size(); i++)
    {
        int v = graph[start][i];
        if(!visited[v])
        {
            DFS(n,comp,v,visited);
        }
    }
}

void getComponents(int n)
{
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++)
        visited[i] = false;
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            vector<int> comp;
            DFS(n,comp,i,visited);
            components.push_back(comp);
        }
    }
}

bool checkPermutation(int n,int *p,int *q)
{
    bool flag = false;

    for(int i = 0; i < components.size(); i++)
    {
        unordered_set<int> p_set;
        unordered_set<int> q_set;
        for(int j = 0; j < components[i].size(); j++)
        {
            int index = components[i][j];
            p_set.insert(p[index]);
            q_set.insert(q[index]);
        }

        for(auto it: p_set)
        {
            if(q_set.find(it) == q_set.end())
            {
                flag = true;
                break;
            }
        }

        for(auto it:q_set)
        {
            if(p_set.find(it) == p_set.end())
            {
                flag = true;
                break;
            }
        }
    }

    return !flag;
}

void printComp(int n)
{
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for(int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    for(int i = 0; i < components.size(); i++)
    {
        for(int j = 0; j < components[i].size(); j++)
        {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,m;
        cin >> n >> m;

        int *p = new int[n];
        int *q = new int[n];

        for(int i = 0; i < n; i++)
        {
            graph[i].clear();
        }

        components.clear();

        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        for(int i = 0; i < n; i++)
        {
            cin >> q[i];
        }

        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        getComponents(n);
        // printComp(n);
        bool ans = checkPermutation(n,p,q);
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}