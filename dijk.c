#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Number of vertices in the graph
int V=0;
  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// A utility function to print the constructed distance array
void printSolution(int dist[], int n,int v)
{
   for (int i = 0; i < V; i++)
   {	
   		if(i==v)
   			continue;
   		else
   		{
   			if(dist[i]>10000)
   				dist[i]=-1;
      		printf("%d ",dist[i]);
   		}
   }
   printf("\n");
}
  
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
  		
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     printSolution(dist, V,src);
}
  
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
    int q,e,u,v,i,j;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&V,&e);
        int graph[V][V];
        for(i=0;i<V;i++)
          for(j=0;j<V;j++)
            graph[i][j]=0;
        for(i=0;i<e;i++)
        {
          scanf("%d%d",&u,&v);
          u--;
          v--;
          graph[u][v]=6;
          graph[v][u]=6;
        }
        scanf("%d",&v);
        // for(i=0;i<V;i++)
        // {
        // 	for(j=0;j<V;j++)
        // 		printf("%d\t",graph[i][j]);
        // 	printf("\n");
        // }
        v--;
        dijkstra(graph, v);
    }
    
  
    return 0;
}