// C++ program to print all paths from a source to destination.
#include<iostream>
#include <list>
#include <vector>
using namespace std;

long k=0,cost=1;
// A directed graph using adjacency list representation
class Graph
{
    long long V;    // No. of vertices in graph
    list<long long> *adj; // Pointer to an array containing adjacency lists
    
    // A recursive function used by printAllPaths()
    void printAllPathsUtil(long long , long long , bool [], long long [], long long &,vector< vector<double> > A);
 
public:
    Graph(long long V);   // Constructor
    void addEdge(long long u, long long v);
    void printAllPaths(long long s, long long d,vector< vector<double> > A);
};
 
Graph::Graph(long long V)
{
    this->V = V;
    adj = new list<long long>[V];
}
 
void Graph::addEdge(long long u, long long v)
{
    adj[u].push_back(v); // Add v to u’s list.
}
 
// Prints all paths from 's' to 'd'
void Graph::printAllPaths(long long s, long long d,vector< vector<double> > A)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
 
    // Create an array to store paths
    long long *path = new long long[V];
    long long path_index = 0; // Initialize path[] as empty
 
    // Initialize all vertices as not visited
    for (long long i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index,A);
}
 
// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(long long u, long long d, bool visited[],
                              long long path[], long long &path_index,vector< vector<double> > A)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {   
        if(path_index==k+1)
        {
            for (long long i = 0; i<path_index; i++)
            {
                // cout << path[i] << " ";
                if(i<path_index-1)
                    cost*=A[path[i]][path[i+1]];
            }
            // cout << endl;
        }
            
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<long long>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index,A);
    }
 
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}
 
// Driver program
int main()
{
    // Create a graph given in the above diagram
    long long n;
    cin >> n;
    long long x;
    long long s;
    long long f;
    long long m;
    cin >> x >> s >> f >> m;
    k=m;
    vector< vector<double> > A(n,vector<double>(n));
    for(long long A_i = 0;A_i < n;A_i++){
       for(long long A_j = 0;A_j < n;A_j++){
          cin >> A[A_i][A_j];
       }
    }

    Graph g(n);
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        {
            if(i!=j)
            {
                g.addEdge(i,j);
            }
        }
    }
    // cout << "Following are all different paths from " << s<< " to " << f << endl;
    g.printAllPaths(s, f,A);
    cout<<x*cost;
    return 0;
}