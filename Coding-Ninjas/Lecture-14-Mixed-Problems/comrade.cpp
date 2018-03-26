#include<bits/stdc++.h>
using namespace std;
#define MAX 100003

vector<int> dfsIn(MAX),dfsOut(MAX);
vector<int> height(MAX);

vector<int> graph[MAX];

int tim = 0;

void dfs(int start,bool *visited,int h)
{
    visited[start] = true;
    height[start] = h;
    dfsIn[start] = ++tim;

    for(int i = 0; i < graph[start].size(); i++)
    {
        int adj = graph[start][i];
        if(!visited[adj])
        {
            dfs(adj,visited,h+1);
        }
    }

    dfsOut[start] = ++tim;
}

int main()
{
    //Write your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n,start;
        cin >> n;

        tim = 0;
        for(int i = 1; i <= n; i++)
        {
            graph[i].clear();
            dfsIn[i] = 0;
            dfsOut[i] = 0;
            height[i] = 0;
        }

        for(int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;

            if(k == 0)
                start = i;
            else
                graph[k].push_back(i);
        }

        bool *visited = new bool[n+1];
        for(int i = 1; i <= n; i++)
            visited[i] = false;
        
        int q;
        cin >> q;

        dfs(start,visited,0);

        while(q--)
        {
            int a,b;
            cin >> a >> b;

            if(dfsIn[b] < dfsIn[a] && dfsOut[b] > dfsOut[a])
            {
                cout << height[a]-height[b] -1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }

    }
    return 0;
}