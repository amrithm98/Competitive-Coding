#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> iPair;

vector<pair<int,int>> graph[100001],graphRev[100001];

void dijkstra_pq_graph(int start,vector<long long int> &distance, int n)
{
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
}

void dijkstra_pq_graphRev(int start,vector<long long int> &distance, int n)
{
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

        for(int i = 0; i < graphRev[vertex].size(); i++)
        {
            int adj = graphRev[vertex][i].first;
            int weight = graphRev[vertex][i].second;
            if(!visited[adj] && distance[adj] > distance[vertex] + weight)
            {
                distance[adj] = distance[vertex] + weight;
                pq.push(make_pair(distance[adj],adj));
            }
        }
    }
}



int main()
{
	int n,m,s,t;
    cin >> n >> m >> s >> t;
    
    for(int i = 0; i < n; i++)
    {
        graph[i].clear();
        graphRev[i].clear();
    }
    
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a-1].push_back(make_pair(b-1,c));
        graphRev[b-1].push_back(make_pair(a-1,c));
    }

    vector<long long int> d1(n),d2(n),d3(n),d4(n);

    dijkstra_pq_graph(s-1,d1,n);
    dijkstra_pq_graphRev(t-1,d2,n);
    dijkstra_pq_graphRev(s-1,d3,n);
    dijkstra_pq_graph(t-1,d4,n);


    // for(int i = 0; i < n; i++)
    // {
    //     cout << d1[i] << " "  << d2[i] << " " << d3[i] << " " << d4[i] << endl;
    // }
    int v = -1;
    long long int dist = 1000000000;

    for(int i = 0; i < n; i++)
    {
        if(i == s-1 || i == t-1)
        {
            continue;
        }
        if(d1[i] + d2[i] + d4[i] + d3[i] < dist)
        {
            dist = d1[i] + d2[i] + d4[i] + d3[i];
            v = i;
            // cout << endl << dist << " " << v;
        }
    }
    if(v != -1)
        cout << dist << endl;
    else
    {
        cout << -1 << endl;
    }
    

	return 0;
}
