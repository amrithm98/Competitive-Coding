#include <bits/stdc++.h>
using namespace std;

bool BFS(int **graph,int n,int *visited,int sv,int ev)
{
    queue<int> que;
    que.push(sv);
    visited[sv] = 1;

    bool found = false;

    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        if(v == ev)
        {
            found = true;
            break;
        }

        for(int i = 0; i < n; i++)
        {
            if(i == sv)
            {
                continue;
            }
            
            if(graph[v][i] == 1 && !visited[i]) 
            {
                visited[i] = 1;
                que.push(i);
            }

        }
    }

    return found;
}


int main() {
    int n,e;
    cin >> n >> e;

    int **graph = new int*[n];
    for(int i = 0;i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }

    int start,end;
    cin >> start >> end; 

    int *visited = new int[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    bool sol = BFS(graph,n,visited,start,end);
    if(sol)
        cout<<"true";
    else    
        cout<<"false";

    cout<<endl;

    return 0;
}
