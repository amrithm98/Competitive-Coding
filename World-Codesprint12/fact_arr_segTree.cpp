#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000

long factorialMod[40];

void nFactModM()
{
    long ans = 1;
    factorialMod[0] = 1;
    for(int i = 1; i < 40 ; i++)
    {
        ans = (ans*i)%MOD;
        factorialMod[i] = ans;
    }
}

long factorial(long n)
{
    if( n >= 40 )
        return 0;
    else
        return factorialMod[n];
}

void buildTree(long *arr,long *tree,long start,long end,long treeNode)
{
    if(start == end)
    {
        tree[treeNode] = factorial(arr[start]);
        return;
    }

    long mid = (start+end)/2;

    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void updateTree(long *arr,long *tree,long start,long end,long treeNode,long idx)
{
    if(start == end)
    {
        arr[idx] = (arr[idx]+1);
        tree[treeNode] = factorial(arr[idx]);
        return;
    }
    long mid = (start + end)/2;
    if(idx > mid)
    {
        updateTree(arr,tree,mid+1,end,2*treeNode+1,idx);
    }
    else
    {
        updateTree(arr,tree,start,mid,2*treeNode,idx);
    }
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
    return ;
}

void updateTreeValue(long *arr,long *tree,long start,long end,long treeNode,long idx,long value)
{
    if(start == end)
    {
        arr[idx] = value;
        tree[treeNode] = factorial(value);
        return;
    }
    long mid = (start + end)/2;

    if(idx > mid)
    {
        updateTreeValue(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    }
    else
    {
        updateTreeValue(arr,tree,start,mid,2*treeNode,idx,value);
    }
    tree[treeNode] = tree[2*treeNode]+ tree[2*treeNode+1];
    return;
    // cout<<"\nUPDATING VALUE";
}

long query(long *arr,long *tree,long start,long end,long treeNode,long left,long right)
{
    if(start > end || start > right || end < left)
    {
        return 0;
    }
    
    if(left <= start && right >= end)
    {
        return tree[treeNode];
    }

    long mid = (start+end)/2;
    long ans1 = query(arr,tree,start,mid,2*treeNode,left,right);
    long ans2 = query(arr,tree,mid+1,end,2*treeNode+1,left,right);
    return ((ans1%MOD)+(ans2%MOD))%MOD;
}

void printTree(long *tree,long n)
{
    for(int i = 1; i < 2*n; i++)
    {
        cout<<tree[i]<<" ";
    }
}

int main() 
{
    long n;
    long m;
    cin >> n >> m;

    nFactModM();

    long arr[100001];
    long tree[400008];

    for(long i = 0; i < n; i++)
        cin >> arr[i];

    buildTree(arr,tree,0,n-1,1);
    // printTree(tree,n);
    for(int i = 0; i < m; i++)
    {
        long a,b,c;
        cin >> a >> b >> c;
        b--;
        c--;
        if(a == 1)
        {
            for(int k = b; k <= c; k++)
                    updateTree(arr,tree,0,n-1,1,k);
        }
        else if (a == 2)
        {
                long ans = query(arr,tree,0,n-1,1,b,c);
                cout<<ans<<endl;
        }
        else 
        {
                updateTreeValue(arr,tree,0,n-1,1,b,c+1);
        }
    }
    return 0;
}
