#include <bits/stdc++.h>
using namespace std;

void BFS(int **graph,int n,int sv,int *visited)
{
    queue<int> que;
    que.push(sv);
    visited[sv] = 1;

    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        cout<< v + 1<<" ";

        for(int i = 0; i < n; i++)
        {
            if(i == sv)
            {
                continue;
            }
            
            if(graph[v][i] != 0 && !visited[i]) 
            {
                visited[i] = 1;
                que.push(i);
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin >> n;

    int **graph = new int*[n];
    int **graphRev = new int*[n];
    for(int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        graphRev[i] = new int[n];

        for(int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
            graphRev[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        string s;
        getline(cin,s);
        string test = "";
        int j;
        for( j = 0; j < s.size(); j++)
        {
            if(s[j] == ' ')
            {
                j++;
                break;
            }
            else
            {
                test += s[j];
            }
        }
        if(s[j] == 'k')
        {
            int node = stoi(test);
            graph[i][node-1] = 1;
            graphRev[node-1][i] = 1;
        }
        else if(s[j] == 'i')
        {
            int node = stoi(test);
            graph[i][node-1] = 2;
            graphRev[node-1][i] = 2;
        }
    }
    cin >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int *visited = new int[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    BFS(graph,n,0,visited);

    return 0;
}
