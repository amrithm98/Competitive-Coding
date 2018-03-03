#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> iPair;

void dijkstra(vector<unordered_map<int,int>> graph,int n,int s)
{
    int *distance = new int[n+1];
    bool *visited = new bool[n+1];

    for(int i = 1; i <= n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
    pq.push(make_pair(0,s));

    distance[s] = 0;

    while(!pq.empty())
    {
        pair<int,int> edge = pq.top();
        pq.pop();

        int vertex = edge.second;
        visited[vertex] = true;

        for(auto it : graph[vertex])
        {
            int adj = it.first;
            int weight = it.second;

            if(!visited[adj] && (distance[vertex] + weight < distance[adj]))
            {
                distance[adj] = distance[vertex] + weight;
                pq.push(make_pair(distance[adj],adj));
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(s != i)          
        {
            if(distance[i] == INT_MAX)
                cout << "-1 ";
            else
                cout << distance[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int m;
        cin >> n >> m;
        
        unordered_map<int,int> init;
        init.clear();
        vector<unordered_map<int,int>> graph(n+1,init);
        
        for(int a1 = 0; a1 < m; a1++)
        {
            int x;
            int y;
            int r;
            cin >> x >> y >> r;

            if(graph[x].find(y) == graph[x].end())
            {
                graph[x][y] = r;
                graph[y][x] = r;
            }
            else
            {
                if(graph[x][y] > r)
                {
                    graph[x][y] = r;
                    graph[y][x] = r;
                }
            }
        }
        // for(auto it : graph)
        // {
        //     for(auto it1 : it)
        //     {
        //         cout << "( " << it1.first << "," << it1.second << " )";
        //     }
        //     cout << endl;
        // }
        int s;
        cin >> s;
        dijkstra(graph,n,s);
    }

    return 0;
}
