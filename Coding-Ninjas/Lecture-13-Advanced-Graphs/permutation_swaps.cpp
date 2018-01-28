#include <bits/stdc++.h>
using namespace std;

void DFS(int **graph,bool *visited,int n,unordered_set<int>* comp,int start)
{
    visited[start] = true;
    comp->insert(start);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && graph[start][i] != 0)
        {
            DFS(graph,visited,n,comp,i);
        }
    }
}

unordered_set<unordered_set<int>*>* getComponents(int **graph,int n)
{
    bool *visited = new bool[n];

    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            unordered_set<int> *comp = new unordered_set<int>();
            DFS(graph,visited,n,comp,i);
            output->insert(comp);
        }
    }
    return output;
}

bool checkPermutation(int *p,int *q,unordered_set<unordered_set<int>*>* components,int n)
{
    unordered_set<unordered_set<int>*>::iterator mainIt = components->begin();
    while(mainIt != components->end())
    {
        unordered_set<int> *comp = *mainIt;
        unordered_set<int>::iterator it = comp->begin();
        unordered_set<int> elems1,elems2;
        // cout << endl;
        while(it != comp->end())
        {
            elems1.insert(p[*it]);
            elems2.insert(q[*it]);
            // cout << *it << " ";
            it++;
        }
        // cout << endl;
        bool flag = true;
        for(auto elemIt : elems1)
        {
            if(elems2.find(elemIt) == elems2.end())
            {
                flag = false;
                return false;
            }
        }
        for(auto elemIt : elems2)
        {
            if(elems1.find(elemIt) == elems1.end())
            {
                flag = false;
                return false;
            }
        }
        mainIt++;
    }   
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;

        int *p = new int[n];
        int *q = new int[n];

        for(int i = 0 ; i < n; i++)
            cin >> p[i];
        
        for(int i = 0 ; i < n; i++)
            cin >> q[i];

        int **graph = new int*[n];

        for(int i = 0; i < n; i++)
        {
            graph[i] = new int[n];
            for(int j = 0; j < n; j++)
                graph[i][j] = 0;
        }

        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            graph[a-1][b-1] = 1;
            graph[b-1][a-1] = 1;
        }

        unordered_set<unordered_set<int>*>* components = getComponents(graph,n);
        bool sol = checkPermutation(p,q,components,n);

        if(sol)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" <<endl;
        }
    }

    return 0;
}