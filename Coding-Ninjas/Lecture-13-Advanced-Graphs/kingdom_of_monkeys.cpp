#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> components;
vector<int> graph[100001];

long long int weightedSum(vector<int> &comp,long long int *weights)
{
    long long int sum = 0;
    for(int i = 0; i < comp.size(); i++)
    {
        sum += weights[comp[i]];
    }
    return sum;
}

void BFS(int start,int n,vector<int> &comp,bool *visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        comp.push_back(node);

        for(int i = 0; i < graph[node].size(); i++)
        {
            int curr = graph[node][i];

            if(!visited[curr])
            {
                visited[curr] = true;
                q.push(curr);
            }
        }
    }
}

long long int maxWeightComponent(long long int *weight, int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    long long int max_weight = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            vector<int> comp;
            BFS(i,n,comp,visited);
            components.push_back(comp);
            long long int weightOfComp = weightedSum(comp,weight);
            if(weightOfComp > max_weight)
                max_weight = weightOfComp;
        }
    }

    return max_weight;
}

int main()
{
	//code
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        long long int *weights = new long long int[n];
        components.clear();

        for(int i = 0; i < n; i++)
        {
            graph[i].clear();
        }

        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        for(int i = 0; i < n; i++)
            cin >> weights[i];

        cout << maxWeightComponent(weights,n) << endl;
    }
	return 0;
}
