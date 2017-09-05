#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>> adj,vector<bool>visited,int vertex,int *ans)
{
    visited[vertex]=true;
    int num=0,temp=0;
    cout<<"\nVertex: "<<vertex;
    for(int i=0;i<visited.size();i++)
    {
        if(!visited[i] && adj[vertex][i]==1)
        {
            temp=dfs(adj,visited,i,ans);
            if(temp%2!=0)
            {
                num+=temp;
            }
            else
            {
                (*ans)++;
            }
            cout<<"\nTemp: "<<temp<<" Ans: "<<*ans<<" Num: "<<num<<"\n";
        }
    }
    return num+1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1]=1;
        graph[b-1][a-1]=1;
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //                 cout<<graph[i][j]<<" ";
    //     cout<<"\n";
    // }
    vector<bool> visited(n);
    for(int i=0;i<n;i++)
        visited[i]=false;
    int ans=0;
    dfs(graph,visited,0,&ans);
    cout<<ans;
    return 0;
}
