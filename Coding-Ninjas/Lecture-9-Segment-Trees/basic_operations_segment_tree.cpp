#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    int *tree = new int[2*n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    buildTree(arr,tree,0,n-1,1);
    
    for(int i = 1; i < 2*n; i++)
        cout<<tree[i]<<" ";

    
    while(1)
    {
        cout<<"\n1. Update\n2.Query\nEnter Choice: ";
        int ch;
        cin >> ch;
        switch(ch)
        {
            case 1:
                int i,v;
                cout<<"\nEnter Index & Value to Update: ";
                cin >> i >> v;
                updateTree(arr,tree,0,n-1,1,i,v);
                for(int i = 1; i < 2*n; i++)
                    cout<<tree[i]<<" ";
                break;
            case 2:
                int a,b;
                cout<<"\nEnter Range To Query: ";
                cin >> a >> b;
                int res = query(arr,tree,0,n-1,1,a,b);
                cout<<"\nResult: "<<res<<endl;
                break;
        }
    }
    

    
    return 0;
}