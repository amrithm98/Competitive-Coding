#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minKeyVertex(vector<int> &key,vector<bool> &mstSet)
{
    int min=INT8_MAX;
    int min_index;
    for(int i=0;i<key.size();i++)
    {
        if(mstSet[i]==false && key[i]<min)
        {
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
} 

int primsMST(vector<vector<int>> graph,int n,int s)
{
    vector<int> parent(n),key(n);
    vector<bool> mstSet(n);

    int i,v;
    for(i=0;i<n;i++)
    {
        mstSet[i]=false;
        key[i]=INT8_MAX;
    }

    key[s]=0;
    parent[s]=-1;

    for(i=0;i<n-1;i++)
    {   
        int u=minKeyVertex(key,mstSet);
        mstSet[u]=true;

        for(v=0;v<n;v++)
        {
            if(graph[u][v]!=0 && mstSet[v]==false && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }

    }

    int mstWeight=0;
    for(i=1;i<n;i++)
    {
        // cout<<"\n"<<parent[i]<<"->"<<i<<" "<<graph[i][parent[i]];
        mstWeight+=graph[i][parent[i]];
    }

    return mstWeight;
}

int main() 
{
    int n,m,s;
    cin>>n>>m;

    int i=0;

    vector<vector<int>> graph(n,vector<int>(n));

    for(;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        graph[a-1][b-1]=w;
        graph[b-1][a-1]=w;
    }

    cin>>s;

    cout<<primsMST(graph,n,s-1)<<endl;
    return 0;
}
