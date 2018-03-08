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

    disjointSet(int n)
    {
        disjSet = new Node[n];
        this->n = n;

        for(int i = 0; i < n; i++)
        {
            disjSet[i].parent = i;
            disjSet[i].rank = 0;
        }

    }

    int find(int child)
    {
        if(disjSet[child].parent != child)
        {
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
        }
        else if(disjSet[parentA].rank > disjSet[parentB].rank)
        {
            disjSet[parentB].parent = parentA;
        }
        else
        {
            disjSet[parentA].parent = parentB;
            disjSet[parentB].rank++;
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
            connectedComponents[disjSet[i].parent].insert(i);
        }

        cout << endl;
        for(auto it : connectedComponents)
        {
            cout << "\nParent is " << it.first << " : ";
            for(auto it1 : it.second)
            {
                cout << it1 << " ";
            }
            cout << endl;
        }
    }

};

int main()
{
    int n,m;
    cin >> n >> m;

    Edge *graph = new Edge[m];
    
    disjointSet ds(n);

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;

        graph[i] = {a,b};
    }

    for(int i = 0; i < m; i++)
    {
        ds.Union(graph[i].start,graph[i].end);
    }

    ds.print();
    return 0;

}