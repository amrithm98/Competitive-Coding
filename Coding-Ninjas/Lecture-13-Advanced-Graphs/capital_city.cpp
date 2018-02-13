#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
vector<int> graphT[100001];
vector<set<int>> components;
map<int,int> componentMap;

void DFS(int start,stack<int> &finishedStack, bool *visited)
{
    visited[start] = true;
    for(int i = 0; i < graph[start].size(); i++)
    {
        int adj = graph[start][i];

        if(!visited[adj])
        {
            DFS(adj,finishedStack,visited);
        }
    }

    finishedStack.push(start);
}

void DFS2(int start, bool *visited,set<int> &comp)
{
    visited[start] = true;
    comp.insert(start);

    for(int i = 0; i < graphT[start].size(); i++)
    {
        int adj = graphT[start][i];
        if(!visited[adj])
        {
            DFS2(adj,visited,comp);
        }
    }
}

void getSCC(int n)
{
    bool *visited = new bool[n];
    stack<int> finishedStack;

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            DFS(i,finishedStack,visited);
        }
    }

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    while(!finishedStack.empty())
    {
        int top = finishedStack.top();
        finishedStack.pop();

        if(!visited[top])
        {
            set<int> comp;
            DFS2(top,visited,comp);
            components.push_back(comp);
        }
    }
}

void printSCC()
{
    cout << endl;
    for(int i = 0; i < components.size(); i++)
    {
        for(auto it : components[i])
        {
            cout << it + 1 << " ";
        }
        cout << endl;
    }
}

void getCapitals(int n)
{
    int num = components.size(); 
    int *inDegree = new int[num];

    for(int i = 0; i < num; i++)
    {
        inDegree[i] = 0;

        for(auto it : components[i])
        {
            componentMap[it] = i;
        }
    }
    
    // for(auto it : componentMap)
    //     cout << it.first + 1<< " " << it.second << endl;

    for(int i = 0; i < n; i++)
    {
        for(auto it : graphT[i])
        {
            if(componentMap[i] != componentMap[it])
            {
                inDegree[componentMap[it]]++;
            }
        }
    }
    // cout << endl;

    // for(int i = 0; i < num ; i++)
    //     cout << inDegree[i] << " ";

    // cout << endl;

    int index = -1;
  	int i;
    for( i = 0; i < num; i++)
    {
        if(inDegree[i] == 0 && index == -1)
        {
            index = i;
        }
        else if(inDegree[i] == 0 && index != -1)
        {
          	index = -1;
            break;
        }
    }

    if(index == -1)
        cout << 0 << endl;
    else
    {
        cout << components[index].size() << endl;

        for(auto it : components[index])
            cout << it + 1<< " ";
    }
}

int main()
{

    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        graph[i].clear();
        graphT[i].clear();
    }

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graphT[b-1].push_back(a-1);
    }

    getSCC(n);
    // printSCC();
    getCapitals(n);
    return 0;
}