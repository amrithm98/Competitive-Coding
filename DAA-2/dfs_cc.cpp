#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> components;
vector<int> graph[100001];
long long int countOps;

void DFS(int start, int n, bool *visited, vector<int> &comp)
{
    countOps += 2;
    visited[start] = true;
    comp.push_back(start);

    for(int i = 0; i < graph[start].size(); i++)
    {
        countOps += 1;
        int adj = graph[start][i];
        if(!visited[adj])
        {
            countOps++;
            DFS(adj,n,visited,comp);
        }
    }
}

void getComponents(int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    
    countOps += n;

    for(int i = 0; i < n; i++)
    {
        countOps++;

        if(!visited[i])
        {
            countOps += 3;
            vector<int> comp;
            DFS(i,n,visited,comp);
            components.push_back(comp);
        }
    }
}

void printComp()
{
    for(auto it : components)
    {
        for(auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
}

int main()
{

    int t;
    // cin >> t;"input.txt"
    ifstream input("input.txt");
    ofstream output("output1.txt");

    input >> t;
    int k = 1;
    while(k <= t)
    {
        countOps = 0;

        int n,m;
        input >> n >> m;

        for(int i = 0; i < n; i++)
            graph[i].clear();
        
        components.clear();

        for(int i = 0; i < m; i++)
        {
            int a,b;
            input >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // countOps += (n+ 2*m);

        getComponents(n);
        printf("\nGRAPH %d : ",k);

        printComp();
        printf("\nNumber of Operations:  %d",countOps);
        
        output << (n+m) << " " << countOps << endl;
        k++;
    }
    return 0;
}