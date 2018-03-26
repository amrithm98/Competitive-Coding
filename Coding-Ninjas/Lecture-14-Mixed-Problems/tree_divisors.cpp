#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005

vector<int> graph[MAX];
vector<int> divisor(MAX,1);
vector<int> included(MAX,0);
vector<int> excluded(MAX,0);

void divisors()
{
    for(int i = 2; i < MAX; i++)
    {
        for(int j = i; j < MAX; j += i)
        {
            divisor[j]++;
        }   
    }
}

void DFS(int start,bool *visited)
{
    visited[start] = true;
    included[start] = divisor[start];
    excluded[start] = 0;
    for(int i = 0; i < graph[start].size(); i++)
    {
        int adj = graph[start][i];
        if(!visited[adj])
        {
            DFS(adj,visited);
            excluded[start] += max(included[adj],excluded[adj]);
            included[start] += excluded[adj];
        }
    }
}

int main()
{
    
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        graph[i].clear();
    }

    for(int i = 1; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }   

    divisors();

    bool *visited = new bool[n+2];
    for(int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }

    DFS(1,visited);
    cout << max(included[1],excluded[1]) << endl;
    return 0;
}