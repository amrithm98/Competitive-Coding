#include <bits/stdc++.h>
using namespace std;

void rangeUpdateLazy(int *arr,int *tree,int *lazy,int start,int end,int inc,int low,int high,int pos)
{
    if(low > high)
    {
        return;
    }
    if(lazy[pos] != 0)
    {
        tree[pos] += lazy[pos];
        if(low != high)
        {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }
        lazy[pos] = 0;

    }
    //No Overlap
    if(start > high || end < low)
    {
        return;
    }
    //Total Overlap
    if(start <= low && end >= high)
    {
        tree[pos] += inc;
        if(low != high)
        {
            lazy[2*pos] += inc;
            lazy[2*pos+1] += inc;
        }
        return;
    }
    //Partial Overlap
    int mid = (low+high)/2;
    rangeUpdateLazy(arr,tree,lazy,start,end,inc,low,mid,2*pos);
    rangeUpdateLazy(arr,tree,lazy,start,end,inc,mid+1,high,2*pos+1);
    tree[pos] = tree[2*pos] + tree[2*pos+1];

}

int queryLazy(int *arr,int *tree,int *lazy,int start,int end,int low,int high,int pos)
{
    if(low > high)
    {
        return 0;
    }
    if(lazy[pos] != 0)
    {
        tree[pos] += lazy[pos];
        if(low != high)
        {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];

        }
        lazy[pos] = 0;
    }
    //No Overlap
    if(start > high || end < low)
    {
        return 0;
    }
    //Total Overlap
    if(start <= low && end >= high)
    {
        return tree[pos];
    }
    //Partial Overlap
    int mid = (low + high)/2;
    return queryLazy(arr,tree,lazy,start,end,low,mid,2*pos)+queryLazy(arr,tree,lazy,start,end,mid+1,high,2*pos+1);

}

void buildTree(int *arr,int *tree,int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start+end)/2;

    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void updateTree(int *arr,int *tree,int start,int end,int treeNode,int idx,int value)
{
    if(start == end)
    {
        arr[idx] = value;
        tree[treeNode] = value;
        return;
    }
    
    int mid = (start + end)/2;
    if(idx > mid)
    {
        updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    }
    else
    {
        updateTree(arr,tree,start,mid,2*treeNode,idx,value);
    }
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int query(int *arr,int *tree,int start,int end,int treeNode,int left,int right)
{
    if(start > right || end < left)
    {
        return 0;
    }
    if(start >= left && end <=right)
    {
        return tree[treeNode];
    }

    int mid = (start+end)/2;
    int ans1 = query(arr,tree,start,mid,2*treeNode,left,right);
    int ans2 = query(arr,tree,mid+1,end,2*treeNode+1,left,right);

    return ans1+ans2;

}

void printTree(int *tree,int n)
{
    for(int i = 1; i < 2*n; i++)
        cout<<tree[i]<<" ";
    cout<<"\n";
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    int *tree = new int[2*n];
    int *lazy = new int[2*n];
    memset(lazy,0,2*n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    buildTree(arr,tree,0,n-1,1);
    
    for(int i = 1; i < 2*n; i++)
        cout<<tree[i]<<" ";

    
    while(1)
    {
        cout<<"\n1. Update\n2.Query\nLAZY\n=======\n3. Range Update\n4. Range Query\nEnter Choice: ";
        int ch;
        cin >> ch;
        int a,b,c,i,v,res;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter Index & Value to Update: ";
                cin >> i >> v;
                updateTree(arr,tree,0,n-1,1,i,v);
                for(int i = 1; i < 2*n; i++)
                    cout<<tree[i]<<" ";
                break;
            case 2:
                cout<<"\nEnter Range To Query: ";
                cin >> a >> b;
                res = query(arr,tree,0,n-1,1,a,b);
                cout<<"\nResult: "<<res<<endl;
                break;
            case 3:
                cout<<"\nEnter Range To Query & Value: ";
                cin >> a >> b >> c;
                rangeUpdateLazy(arr,tree,lazy,a,b,c,0,n-1,1);
                break;
            case 4:
                cout<<"\nEnter Range To Query: ";
                cin >> a >> b;
                res = queryLazy(arr,tree,lazy,a,b,0,n-1,1);
                cout<<"\nResult: "<<res<<endl;
                break;
        }
        printTree(tree,n);
    }
    

    
    return 0;
}