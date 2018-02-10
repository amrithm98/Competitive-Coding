#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100001],graphRev[100001];

int findMinVertex(int n,bool *visited,vector<int> &distance)
{
    int minVertex = -1;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void dijkstra(int start,vector<int> &distance,int flag,int n)
{
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[start] = 0;

    if(flag == 0)
    {
        for(int i = 0; i < n; i++)
        {
            int minVertex = findMinVertex(n,visited,distance);
            visited[minVertex] = true;
            for(int j = 0; j < graph[minVertex].size(); j++)
            {
                pair<int,int> node = graph[minVertex][j];
                if(!visited[node.first] && node.second + distance[minVertex] < distance[node.first] )
                {
                    distance[node.first] = node.second + distance[minVertex];
                }
            }

        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            int minVertex = findMinVertex(n,visited,distance);
            visited[minVertex] = true;

            for(int j = 0; j < graphRev[minVertex].size(); j++)
            {
                pair<int,int> node = graphRev[minVertex][j];
                if(!visited[node.first] && node.second + distance[minVertex] < distance[node.first] )
                {
                    distance[node.first] = node.second + distance[minVertex];
                }
            }

        }
    }
}

int main()
{
	int n,m,s,t;
    cin >> n >> m >> s >> t;
    
    for(int i = 0; i < n; i++)
        graph[i].clear();
    
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a-1].push_back(make_pair(b-1,c));
        graphRev[b-1].push_back(make_pair(a-1,c));
    }

    vector<int> d1(n),d2(n),d3(n),d4(n);

    dijkstra(s-1,d1,0,n);
    dijkstra(t-1,d2,1,n);
    dijkstra(s-1,d3,1,n);
    dijkstra(t-1,d4,0,n);

    for(int i = 0; i < n; i++)
    {
        cout << d1[i] << " "  << d2[i] << " " << d3[i] << " " << d4[i] << endl;
    }

    

	return 0;
}
