#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int *dist,bool *visited,int V)
{
    int minVertex = -1;
    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex]) )
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int **graph,int n)
{
    int *distance = new int[n];
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[0] = 0;

    for(int i = 0; i < n; i++)
    {
        int minVertex = findMinVertex(distance,visited,n);
        visited[minVertex] = true;

        for(int j = 0; j < n; j++)
        {
            if(graph[minVertex][j] != 0)
            {
                if(!visited[j] && distance[minVertex] + graph[minVertex][j] < distance[j])
                {
                    distance[j] = distance[minVertex] + graph[minVertex][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;

    int **graph = new int*[V];

    for(int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for(int j = 0; j < V; j++)
          graph[i][j] = 0;
    }

    for(int i = 0; i < E; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }    

    dijkstra(graph,V);
    
    return 0;
}