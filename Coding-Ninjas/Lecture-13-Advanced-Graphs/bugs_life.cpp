#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int> *graph,int n)
{
    set<int> colorSet[2];
    queue<int> pending;
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++)
        visited[i] = false;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            colorSet[0].insert(i);
            pending.push(i);

            while(!pending.empty())
            {
                int current = pending.front();
                pending.pop();

                visited[current] = true;

                int currentSet = (colorSet[0].count(current) > 0) ? 0 : 1;

                for(int j = 0; j < graph[current].size(); j++)
                {
                    int adj = graph[current][j];

                    if(colorSet[0].count(adj) == 0 && colorSet[1].count(adj) == 0)
                    {
                        colorSet[1 - currentSet].insert(adj);
                        pending.push(adj);
                    }
                    else if(colorSet[currentSet].count(adj) > 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

int main()
{
	int t;
    cin >> t;

    int k = 1;
    while(k <= t)
    {
        int n,m;
        cin >> n >> m;

        vector<int> *graph = new vector<int>[n];
        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        bool ans = isBipartite(graph,n);

        cout << "Scenario #" << k << ":" << endl;
        if(!ans)
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;
        k++;
    }

	return 0;
}
