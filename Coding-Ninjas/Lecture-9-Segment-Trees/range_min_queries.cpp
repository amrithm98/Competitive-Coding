#include<bits/stdc++.h>
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
    buildTree(arr,tree,mid+1,end,2*treeNode + 1);

    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

void updateTree(int *arr,int *tree,int start,int end,int treeNode,int index,int value)
{
    if(start == end)
    {
        arr[index] = value;
        tree[treeNode] = value;
        return;
    }

    int mid = (start + end)/2;

    if(index > mid)
    {
        updateTree(arr,tree,mid+1,end,2*treeNode+1,index,value);
    }
    else
    {
        updateTree(arr,tree,start,mid,2*treeNode,index,value);
    }

    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

int query(int *arr,int *tree,int start,int end,int treeNode,int l,int r)
{
    if(start > r || end < l)
    {
        return INT_MAX;
    }

    if(start >= l && end <= r)
    {
        return tree[treeNode];
    }
    
    int mid = (start + end)/2;
    int ans1 = query(arr,tree,start,mid,2*treeNode,l,r);
    int ans2 = query(arr,tree,mid+1,end,2*treeNode+1,l,r);
    
    return min(ans1,ans2);
}

void printTree(int *tree,int n)
{
    for(int i = 1; i <= 2*n; i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int n,m;
    cin >> n >> m;
    int *arr = new int[n];
    int *tree = new int[4*n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    buildTree(arr,tree,0,n-1,1);
    // printTree(tree,n);

    for(int i = 0; i < m; i++)
    {
        char q;
        int l,r;
        cin >> q >> l >> r;
        if(q == 'q')
        {
            cout<<query(arr,tree,0,n-1,1,l-1,r-1)<<endl;
        }
        else if(q == 'u')
        {
            updateTree(arr,tree,0,n-1,1,l-1,r);
            // printTree(tree,n);
        }
    }
    return 0;

	// Write your code here
}