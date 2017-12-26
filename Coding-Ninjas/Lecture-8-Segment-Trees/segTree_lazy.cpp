#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000000

long arr[MAX];
long tree[4*MAX];
long lazy[4*MAX];

void constructTree(int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode] = arr[start];
        return ;
    }
    int mid = (start + end)/2;
    constructTree(start,mid,2*treeNode + 1);
    constructTree(mid+1,end,2*treeNode + 2);
    tree[treeNode] = tree[2*treeNode + 1] + tree[2*treeNode + 2];
}

void updateRange(int start,int end,int treeNode,int left,int right,long val)
{
    if(lazy[treeNode] != 0)
    {
        tree[treeNode] += (end-start+1)*lazy[treeNode];

        if(start != end)
        {
            lazy[2*treeNode + 1] += lazy[treeNode];
            lazy[2*treeNode + 2] += lazy[treeNode];
        }

        lazy[treeNode] = 0;
    }

    //Out of range
    if(start > end || start > right || end < left)
    {
        return;
    }
 
    //Current Segment - Fully in Range
    if(start >= left && end <= right)
    {
        tree[treeNode] += (end-start+1)*val;

        if(start != end)
        {
            lazy[2*treeNode + 1] += val;
            lazy[2*treeNode + 2] += val;
        }
        return ;
    }

    int mid = (start+end)/2;
    updateRange(start,mid,2*treeNode + 1,left,right,val);
    updateRange(mid+1,end,2*treeNode + 2,left,right,val);

    tree[treeNode] = tree[2*treeNode + 1] + tree[2*treeNode + 2];

}

long queryRange(int start,int end,int left,int right,int treeNode)
{
    if(lazy[treeNode] != 0)
    {
        tree[treeNode] += (end-start+1)*lazy[treeNode];

        if(start != end)
        {
            lazy[2*treeNode + 1] += lazy[treeNode];
            lazy[2*treeNode + 2] += lazy[treeNode];
        }

        lazy[treeNode] = 0;
    }

    if(start > end || start > right || end <left)
    {
        return 0;
    }

    if(start >= left && end <= right)
    {
        return tree[treeNode];
    }

    //Partial

    int mid = (start + end)/2;
    return queryRange(start,mid,left,right,2*treeNode + 1) + queryRange(mid+1,end,left,right,2*treeNode + 2);
}

void printTree(int n)
{
    cout<<"\nTREE\n=============\n";
    for(int i = 0; i < 2*n; i++)
        cout<<tree[i]<< " ";
    cout<<"\n======================\n";
}

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >>arr[i];
    }

    memset(lazy,0,4*MAX);

    constructTree(0,n-1,0);

    printTree(n);

    for(int i = 0; i < m; i++)
    {
        long a,b,c;
        cin >> a >> b >> c;
        if( a == 1)
        {
            updateRange(0,n-1,0,b-1,c-1,1);
        }
        else if(a == 2)
        {
            long ans = queryRange(0,n-1,b-1,c-1,0);
            cout<<"\nQuery : "<<ans<<endl;
        }
        else if(a == 3)
        {
            updateRange(0,n-1,0,b-1,b-1,c);
        }
        printTree(n);
    }

    return 0;
}