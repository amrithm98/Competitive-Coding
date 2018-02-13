#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
vector<int> graphT[100001];
vector<set<int>> components;

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
}