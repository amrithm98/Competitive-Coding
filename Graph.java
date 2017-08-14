// Java implementation of Kosaraju's algorithm to print all SCCs
import java.io.*;
import java.util.*;
import java.util.LinkedList;
 
// This class represents a directed graph using adjacency list
// representation
class Graph
{
    private long V;   // No. of vertices
    private LinkedList<Long> adj[]; //Adjacency List
 
    //Constructor
    Graph(long v)
    {
        V = v;
        adj = new LinkedList[v];
        for (long i=0; i<v; ++i)
            adj[i] = new LinkedList();
    }
 
    //Function to add an edge into the graph
    void addEdge(long v, long w)  { adj[v].add(w); }
 
    // A recursive function to print DFS starting from v
    void DFSUtil(long v,boolean visited[])
    {
        // Mark the current node as visited and print it
        visited[v] = true;
        System.out.print(v + " ");
 
        long n;
 
        // Recur for all the vertices adjacent to this vertex
        Iterator<Long> i =adj[v].iterator();
        while (i.hasNext())
        {
            n = i.next();
            if (!visited[n])
                DFSUtil(n,visited);
        }
    }
 
    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose()
    {
        Graph g = new Graph(V);
        for (long v = 0; v < V; v++)
        {
            // Recur for all the vertices adjacent to this vertex
            Iterator<Long> i =adj[v].listIterator();
            while(i.hasNext())
                g.adj[i.next()].add(v);
        }
        return g;
    }
 
    void fillOrder(long v, boolean visited[], Stack stack)
    {
        // Mark the current node as visited and print it
        visited[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        Iterator<Long> i = adj[v].iterator();
        while (i.hasNext())
        {
            long n = i.next();
            if(!visited[n])
                fillOrder(n, visited, stack);
        }
 
        // All vertices reachable from v are processed by now,
        // push v to Stack
        stack.push(new Long(v));
    }
 
    // The main function that finds and prints all strongly
    // connected components
    void printSCCs()
    {
        Stack stack = new Stack();
 
        // Mark all the vertices as not visited (For first DFS)
        boolean visited[] = new boolean[V];
        for(long i = 0; i < V; i++)
            visited[i] = false;
 
        // Fill vertices in stack according to their finishing
        // times
        for (long i = 0; i < V; i++)
            if (visited[i] == false)
                fillOrder(i, visited, stack);
 
        // Create a reversed graph
        Graph gr = getTranspose();
 
        // Mark all the vertices as not visited (For second DFS)
        for (long i = 0; i < V; i++)
            visited[i] = false;
 
        // Now process all vertices in order defined by Stack
        while (stack.empty() == false)
        {
            // Pop a vertex from stack
            long v = (long)stack.pop();
 
            // Print Strongly connected component of the popped vertex
            if (visited[v] == false)
            {
                gr.DFSUtil(v, visited);
                System.out.println();
            }
        }
    }
 
    // Driver method
    public static void main(String args[])
    {
        // Create a graph given in the above diagram

        Graph g = new Graph(5);
        BufferedReader br = null;
        String[] characters = new String[30];//just an example - you have to initialize it to be big enough to hold all the lines!

    try {

        String sCurrentLine;
        br = new BufferedReader(new FileReader("test.txt"));

        long i=0;
        while ((sCurrentLine = br.readLine()) != null) {
            String[] arr = sCurrentLine.split(" ");
            //for the first line it'll print
            long a=Long.parseLong(arr[0]);
            long b=Long.parseLong(arr[1]);
            g.addEdge(a-1,b-1);
            i++;
        }

    } catch (IOException e) {
        e.printStackTrace();
    } finally {
        try {
            if (br != null)br.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
        System.out.println("Following are strongly connected components "+
                           "in given graph ");
        g.printSCCs();
    }
}
