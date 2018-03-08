#include <bits/stdc++.h>
using namespace std;

long long int countOps;

struct Node
{
    int rank;
    int parent;
};

struct Edge
{
    int start;
    int end;
};

class disjointSet
{
    public:

    Node *disjSet;
    int n;
    static int opCount;

    disjointSet(int n)
    {
        opCount = 0;
        disjSet = new Node[n];
        this->n = n;

        for(int i = 0; i < n; i++)
        {
            disjSet[i].parent = i;
            disjSet[i].rank = 0;
        }

        // opCount += (2*n);
    }

    int find(int child)
    {
        opCount++;
        if(disjSet[child].parent != child)
        {
            opCount++;
            disjSet[child].parent = find(disjSet[child].parent);
        }
        return disjSet[child].parent;
    }

    void Union(int a,int b)
    {
        int parentA = find(a);
        int parentB = find(b);

        if(disjSet[parentA].rank < disjSet[parentB].rank)
        {
            disjSet[parentA].parent = parentB;
            opCount += 2;
        }
        else if(disjSet[parentA].rank > disjSet[parentB].rank)
        {
            disjSet[parentB].parent = parentA;
            opCount += 2;
        }
        else
        {
            disjSet[parentA].parent = parentB;
            disjSet[parentB].rank++;
            opCount += 3;
        }
    }

    bool isUnion(int a,int b)
    {
        return find(a) == find(b);
    }

    void print()
    {
        unordered_map<int,set<int>> connectedComponents;
        
        for(int i = 0; i < n; i++)
        {
            opCount++;
            connectedComponents[disjSet[i].parent].insert(i);
        }

        cout << endl;
        for(auto it : connectedComponents)
        {
            for(auto it1 : it.second)
            {
                cout << it1 << " ";
            }
            cout << endl;
        }
    }

};
        
int disjointSet::opCount = 0;

int main()
{
    int t;
    // cin >> t;"input.txt"
    ifstream input("input.txt");
    ofstream output("output2.txt");

    input >> t;
    int k = 1;
    while(k <= t)
    {
        countOps = 0;

        int n,m;
        input >> n >> m;

        Edge *graph = new Edge[m];

        disjointSet ds(n);

        //Initialize rank n parent for n elements

        for(int i = 0; i < m; i++)
        {
            input >> (graph[i].start) >> (graph[i].end);
        }

        // countOps += 2*m;

        for(int i = 0; i < m; i++)
        {
            countOps++;
            if(!ds.isUnion(graph[i].start,graph[i].end))
            {
                countOps++;
                ds.Union(graph[i].start,graph[i].end);
            }
        }

        printf("\nGRAPH %d : ",k);
        ds.print();
        cout << "\nNumber of Operations: " << disjointSet::opCount + countOps << endl;
        output << (n+m) << " " << disjointSet::opCount + countOps << endl;
        k++;
    }
    return 0;
}