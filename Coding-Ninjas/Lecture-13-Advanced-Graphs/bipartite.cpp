#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int> *graph,int n)
{
    set<int> colorSet[2];
    vector<int> pending;

    colorSet[0].insert(0);
    pending.push_back(0);

    while(!pending.empty())
    {
        int current = pending.back();
        pending.pop_back();

        int currentSet = (colorSet[0].count(current) > 0) ? 0 : 1;

        for(int i = 0; i < graph[current].size(); i++)
        {
            int adj = graph[current][i];

            if(colorSet[0].count(adj) == 0 && colorSet[1].count(adj) == 0)
            {
                colorSet[1 - currentSet].insert(adj);
                pending.push_back(adj);
            }
            else if(colorSet[currentSet].count(adj) > 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> *graph = new vector<int>[n];
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool ans = isBipartite(graph,n);
    if(ans) 
        cout << "\nBiColorable";
    else
        cout << "\nNot BiColorable";
}