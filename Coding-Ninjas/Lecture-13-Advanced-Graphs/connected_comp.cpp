#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges,int sv,bool *visited,unordered_set<int> *comp)
{   
    visited[sv] = true;
    comp->insert(sv);
    for(int i = 0; i < edges[sv].size(); i++)
    {
        int next = edges[sv][i];
        if(!visited[next])
        {
            dfs(edges,next,visited,comp);
        }
    }
}

unordered_set<unordered_set<int>*>* getComponents(vector<int> *edges,int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            unordered_set<int> *comp = new unordered_set<int>();
            dfs(edges,i,visited,comp);
            output->insert(comp);
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<int> *edges = new vector<int>[n];
    int e;
    cin >> e;
    for(int i = 0; i < e; i++)
    {
        int a,b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    unordered_set<unordered_set<int>*>* components = getComponents(edges,n);
    unordered_set<unordered_set<int>*>::iterator it = components->begin();
    while(it != components->end())
    {
        unordered_set<int> *comp = *it;
        unordered_set<int>::iterator it1 = comp->begin();
        while(it1 != comp->end())
        {
            cout << *it1 + 1 << " ";
            it1++;
        }
        it++;
        cout << endl;
    }
    
    return 0;
}