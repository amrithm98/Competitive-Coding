#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void lazy_update(int *tree,int *lazy,int start,int end,int low,int high,int val,int treeNode)
{
    if(start > end)
    {
        return;
    }

    if(lazy[treeNode] != 0)
    {
        tree[treeNode] += (high-low)*lazy[treeNode];
        if(start != end)
        {
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
            lazy[treeNode] = 0;
        }
    }

    if(start > high || end < low)
    {
        return;
    }

    if(start >= low && end <= high )
    {
        tree[treeNode] += (high-low)*val;
        if(start != end)
        {
            lazy[2*treeNode] += val;
            lazy[2*treeNode+1] += val;
        }
        return ;
    }

    int mid = (start + end)/2;

    lazy_update(tree,lazy,start,mid,low,high,val,2*treeNode);
    lazy_update(tree,lazy,mid+1,high,low,high,val,2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];

}

void printTree(int *tree,int *lazy,int n)
{
    for(int i = 1; i < 2*n+2; i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    for(int i = 1; i < 2*n+2; i++)
        cout<<lazy[i]<<" ";
    cout<<endl;
}

int query(int *tree,int *lazy,int start,int end,int low,int high,int treeNode)
{
    if(start > end)
    {
        return 0;
    }
    
    if(lazy[treeNode] != 0)
    {
        tree[treeNode] += (high-low+1)*lazy[treeNode];
        if(start != end)
        {
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
            lazy[treeNode] = 0;
        }
    }

    if(start > high || end < low)
    {
        return 0;
    }

    if(start >= low && end <= high)
    {
        return tree[treeNode];
    }

    int mid = (start + end)/2;

    return query(tree,lazy,start,mid,low,high,2*treeNode) + query(tree,lazy,mid+1,end,low,high,2*treeNode+1);
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,q;
        cin >> n >> q;

        int *arr = new int[n+1];
        int *tree = new int[4*(n+1)];
        int *lazy = new int[4*(n+1)];

        for(int i = 1; i <= n; i++)
        {
            arr[i] = 0;
        }

        buildTree(arr,tree,1,n,1);
        printTree(tree,lazy,n);
        for(int i = 0; i < 4*n; i++)
        {
            lazy[i] = 0;
        }

        while(q--)
        {
            int ch;
            cin >> ch;

            int a,b,c;
            if(ch == 0)
            {
                cin >> a >> b >> c;
                lazy_update(tree,lazy,1,n,a,b,c,1);
                printTree(tree,lazy,n);
            }
            else if(ch == 1)
            {
                cin >> a >> b;
                cout<<query(tree,lazy,1,n,a,b,1)<<endl;
            }
        }
    }
    return 0;
}