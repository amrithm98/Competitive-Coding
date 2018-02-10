#include<bits/stdc++.h>
using namespace std;

string BFS(int **graph,int n,int t)
{   
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    
    queue<int> q;
    q.push(0);

    visited[0] = false;
    
    int flag = 0;

    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        // cout << a << " ";
        if(a == t)
        {
            flag = 1; 
            break;
        }

        for(int i = 0; i < n-1; i++)
        {
            if(!visited[i] && graph[a][i])
            {   
                visited[i] = true;
                q.push(i);
            }
        }
    }
    if(flag)
        return "YES";
    else
        return "NO";
}

int main()
{
	//code
    int n,t;
    cin >> n >> t;
    int **graph = new int*[n-1];

    for(int i = 0; i < n-1; i++)
    {
        graph[i] =  new int[n-1];
        for(int j = 0; j < n-1; j++)
            graph[i][j] = 0;
    }

    for(int i = 0; i < n-1; i++)
    {
        int a;
        cin >> a;
        graph[i][i+a] = 1;
    }
    cout << BFS(graph,n-1,t-1) << endl;

	return 0;
}
