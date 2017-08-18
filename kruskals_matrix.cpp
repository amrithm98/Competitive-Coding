#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int find(vector<int> &Parent,int n,int s)
{
    while(Parent[s])
        s=Parent[s];
    return s;
}

int union_find(vector<int> &Parent,int n,int s,int t)
{
    if(s!=t)
    {
        Parent[t]=s;
        return 1;
    }
    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
    int a,b,c,u,v;
    vector<vector<int>> graph(n,vector<int>(n));
    vector<int> Parent(n);
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph[a-1][b-1]=c;
        graph[b-1][a-1]=c;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(graph[i][j]==0)
                graph[i][j]=INT8_MAX;
    }
    int ne=0;
    int min=INT8_MAX;
    int mincost=0;
    while(ne<n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(graph[i][j]<min)
                {
                    min=graph[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(Parent,n,u);
        v=find(Parent,n,v);
        if(union_find(Parent,n,u,v))
        {
            // cout<<ne++<<" "<<a<<" "<<b<<" "<<min;
            ne++;
            mincost+=min;
        }
        graph[a][b]=graph[b][a]=INT8_MAX;
    }
    cout<<mincost;
    return 0;
}