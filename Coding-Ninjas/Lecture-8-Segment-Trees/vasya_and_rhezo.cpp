#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001

long long int A[MAX],B[MAX];

int tree[4*MAX];

void buildTree(int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode] = start;
        return;
    }
    else
    {
        int mid = (start + end)/2;

        buildTree(start,mid,2*treeNode);
        buildTree(mid+1,end,2*treeNode+1);

        if(A[tree[2*treeNode]] != A[tree[2*treeNode+1]])
        {
            if(A[tree[2*treeNode]] > A[tree[2*treeNode + 1]])
            {
                tree[treeNode] = tree[2*treeNode];
            }
            else
            {
                tree[treeNode] = tree[2*treeNode+1];
            }
        }
        else
        {
            if(B[tree[2*treeNode]] > B[tree[2*treeNode+1]])
            {
                tree[treeNode] = tree[2*treeNode+1];
            }
            else if(B[tree[2*treeNode]] < B[tree[2*treeNode+1]])
            {
                tree[treeNode] = tree[2*treeNode];
            }
            else
            {
                tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
            }
        }
    }
}

int query(int start,int end,int left,int right,int treeNode)
{
    if(start > right || end < left)
    {
        return -1;
    }
    if(start >= left && end <= right)
    {
        return tree[treeNode];
    }
    int mid = (start + end)/2;

    int q1 = query(start,mid,left,right,2*treeNode);
    int q2 = query(mid+1,end,left,right,2*treeNode+1);

    if(q1 != -1 && q2 != -1)
    {
        if(A[q1] != A[q2])
        {
            if(A[q1] > A[q2])
            {
                return q1;
            }
            else
            {
                return q2;
            }
        }
        else
        {
            if(B[q1] > B[q2])
            {
                return q2;
            }
            else if(B[q1] < B[q2])
            {
                return q1;
            }
            else
            {
                return min(q1,q2);
            }
        }
    }
    else if(q1 == -1)
    {
        return q2;
    }
    else
    {
        return q1;
    }
    
}

void printTree(int n)
{
    cout<<"\nTREE\n";
    for(int i = 1; i < 2*n; i++)
    {
        cout<<A[tree[i]]<<" "<<B[tree[i]]<<endl;
        // cout<<tree[i]+1<<" ";
    }
}

int main() 
{
    int n,q;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    buildTree(0,n-1,1);

    cin >> q;

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout<<query(0,n-1,l-1,r-1,1)+1<<endl;
    }
    // printTree(n);

    return 0;
}