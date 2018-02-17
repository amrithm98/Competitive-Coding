#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> components;
vector<pair<int,int>> edges[10001];

void DFS(int n,int start,bool *visited,vector<int> &comp)
{
    visited[start] = true;
    comp.push_back(start);

    for(int i = 0; i < edges[start].size(); i++)
    {
        int adj = edges[start][i].first;
        if(!visited[adj])
        {
            DFS(n,adj,visited,comp);
        }
    }
}

void dfs_helper(int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            vector<int> comp;
            DFS(n,i,visited,comp);
            components.push_back(comp);
        }
    }
}

void printComp()
{
    cout << "\nCOMPONENTS: "<< endl;
    for(int i = 0; i < components.size(); i++)
    {
        for(int j = 0; j < components[i].size(); j++)
        {
            cout << components[i][j] + 1 <<  " ";
        }
        cout << endl;
    }
}

int findMinVertex(int *weights,bool *visited,int V)
{
    int minVertex = -1;
    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

pair<int,int> primsMST(int n,bool *visited,int cost)
{    
    int *parent = new int[n];
    int *weights = new int[n];

    for(int i = 0 ; i < n; i++)
    {
        weights[i] = INT_MAX;
        parent[i] = i;
    }

    int sum = 0;

    for(int i = 0; i < n-1; i++)
    {
        int minVertex = findMinVertex(weights,visited,n);
        visited[minVertex] = true;

        for(int j = 0; j < edges[minVertex].size(); j++)
        {
            pair<int,int> adj = edges[minVertex][j];
            if(!visited[adj.first])
            {
                if(adj.second < weights[adj.first])
                {
                    weights[adj.first] = adj.second;
                    parent[adj.first] = minVertex;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if(weights[i] < INT_MAX)
            sum += weights[i];
    }

    // cout << "\nWEIGHT N COMP\n";
    // for(int i = 0; i < components.size(); i++)
    // {
    //     int sum = 0;
    //     cout << endl;
    //     for(auto it : components[i])
    //     {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    //     for(auto it : components[i])
    //     {
    //         cout << weights[it] << " ";
    //         if(weights[it] < INT_MAX)
    //             sum += weights[it];
    //     }
    //     sum = 0;
    // }

    // for(int i = 0; i < n; i++)
    // {
    //     cout << parent[i]+1 << " : " << i+1 << endl;
    // }
    // for(int i = 0; i < n; i++)
    // {
    //     cout << weights[i] << " : " << i+1 << endl;
    // }

    int totalCost = 0;
    int airpCount = 0;

    for(int i = 0; i < components.size(); i++)
    {
        if(components[i].size() == 1)
        {
            airpCount++;
            totalCost += cost;
            continue;
        }
        else
        {
            cout << "\nComponent : " << i << endl;
            int sumWeight = 0;
            for(int j = 1; j < components[i].size(); j++)
            {
                sumWeight += weights[components[i][j]];
            }
            cout << "\nSum Weight : " << sumWeight << endl;
            if(sumWeight >= cost)
            {
                int currAirp = (sumWeight/cost);
                airpCount += currAirp;
                sumWeight = sumWeight%cost;
                totalCost += (sumWeight + currAirp*cost);
            }
            else
            {
                airpCount += 1;
                totalCost += (sumWeight+cost); 
            }
            
        }
    }
    return make_pair(totalCost,airpCount);
}


pair<int,int> mst_helper(int n,int cost)
{
    dfs_helper(n);
    
    int comps = components.size(); 

    bool *visited = new bool[n];

    for(int i = 0; i < n; i++)
        visited[i] = false;


    // for(int i = 0; i < comps; i++)
    // {
    //     if(!visitedMST[i])
    //     {
    //         totalCost += primsMST(components[i],n,visited);
    //         totalCost += cost;
    //         airpCount++;
    //         visitedMST[i] = true;
    //     }
    // }

    // airpCount = (components.size());
    // totalCost += airpCount*cost;
    // totalCost += primsMST(n,visited,cost);

    return primsMST(n,visited,cost);
}

int main()
{
    int t;
    cin >> t;

    int k = 1;

    while(k <= t)
    {
        int n,m,cost;
        cin >> n >> m >> cost;

        for(int i = 0; i < n; i++)
        {
            edges[i].clear();
        }

        for(int i = 0; i < m; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            edges[a-1].push_back(make_pair(b-1,c));
            edges[b-1].push_back(make_pair(a-1,c));
        }
        pair<int,int> ans = mst_helper(n,cost);
        cout <<  "Case #" << k << ": " << ans.first << " " << ans.second << endl;
        printComp();
        components.clear();
        k++;
    }

	return 0;
}
