#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> iPair;

vector<pair<int,int>> graph[100001];

void dijkstra_pq(int n,int start)
{
    long long int *distance = new long long int[n];
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    priority_queue< iPair, vector<iPair> , greater<iPair> > pq;
    pq.push(make_pair(0,start));

    distance[start] = 0;
    while(!pq.empty())
    {
        pair<int,int> minVertex = pq.top();
        pq.pop();

        visited[minVertex.second] = true;

        int vertex = minVertex.second;

        for(int i = 0; i < graph[vertex].size(); i++)
        {
            int adj = graph[vertex][i].first;
            int weight = graph[vertex][i].second;
            if(!visited[adj] && distance[adj] > distance[vertex] + weight)
            {
                distance[adj] = distance[vertex] + weight;
                pq.push(make_pair(distance[adj],adj));
            }
        }
    }

    cout << endl;
    for(int i = 0; i < n; i++)
        cout << distance[i] << " ";
}

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        graph[i].clear();
    }

    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    // cout << endl;
    // for(int i = 0; i < n; i++)
    // {
    //     cout << i << " : ";
    //     for(int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << graph[i][j].second << " ";
    //     }
    //     cout << endl;
    // }

    dijkstra_pq(n,0);

    return 0;

}