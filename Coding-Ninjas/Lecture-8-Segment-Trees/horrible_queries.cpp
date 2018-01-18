#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

long tree[4*MAX];
long lazy[4*MAX];
long arr[MAX];

// void buildTree(int start,int end,int treeNode)
// {
//     if(start == end)
//     {
//         tree[treeNode] = arr[start];
//         return;
//     }

//     int mid = (start + end)/2;

//     buildTree(start,mid,2*treeNode);
//     buildTree(mid+1,end,2*treeNode+1);

//     tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
// }

void update(int start,int end,int treeNode,int startR,int endR,long value)
{
    //Pending Update

    if(lazy[treeNode] != 0)
    {
        tree[treeNode] += (end-start+1)*lazy[treeNode];

        if(start != end)
        {
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }

    //No Overlap

    if(start > end || start > endR || end < startR)
    {
        return;
    }

    //COmplete Overlap
    if(start >= startR && end <= endR)
    {
        tree[treeNode] += (end-start+1)*value;
        if(start != end)
        {
            lazy[2*treeNode] += value;
            lazy[2*treeNode+1] += value;
        }
        return;
    }

    int mid = (start + end)/2;
    update(start,mid,2*treeNode,startR,endR,value);
    update(mid+1,end,2*treeNode+1,startR,endR,value);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
    return;
}

long query(int start,int end,int treeNode,int startR,int endR)
{
    if(start > end)
    {
        return 0;
    }

    if(start > endR || end < startR)
    {
        return 0;
    }

    if(lazy[treeNode] != 0)
    {
        tree[treeNode] += (end-start+1)*lazy[treeNode];

        if(start != end)
        {
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }


    if(start >= startR && end <= endR)
    {
        return tree[treeNode];
    }

    int mid = (start + end)/2;
    long ans1 = query(start,mid,2*treeNode,startR,endR);
    long ans2 = query(mid+1,end,2*treeNode+1,startR,endR);

    return ans1+ans2;

}

void init(int n)
{
    for(int i = 1; i <= n; i++)
        arr[i] = 0;

    for(int i = 1; i < 4*n; i++)
    {
        tree[i] = 0;
        lazy[i] = 0;
    }
}

void printTree(int n)
{
    cout<<endl;
    for(int i = 1; i < 2*n; i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    for(int i = 1; i < 2*n; i++)
        cout<<lazy[i]<<" ";
    cout<<endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,c;
        cin >> n >> c;

        init(n);
        
        // buildTree(1,n,1);
        // printTree(n);

        for(int i = 0; i < c; i++)
        {
            int op,l,r;
            cin >> op >> l >> r;
            if(op == 1)
            {
                long ans = query(1,n,1,l,r);
                cout<<ans<<endl;
            }
            else if(op == 0)
            {
                long val;
                cin >> val;
                update(1,n,1,l,r,val);
                // printTree(n);
            }
        }
    }

    return 0;
}