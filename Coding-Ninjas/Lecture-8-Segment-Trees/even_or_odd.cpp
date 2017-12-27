#include<bits/stdc++.h>
using namespace std;

long long int arr[100001];
long long int tree[400004];

void buildTree(long long int start,long long int end,long long int treeNode)
{
    if(start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }
    else
    {
        long long int mid = (start + end)/2;
        buildTree(start,mid,2*treeNode);
        buildTree(mid+1,end,2*treeNode+1);
        tree[treeNode] = tree[2*treeNode + 1] + tree[2*treeNode];
    }
}

void update(long long int start,long long int end,long long int treeNode,long long int index,long long int value)
{
    if(start == end)
    {
        // cout<<"\nVALUE: "<<value<<" "<<tree[treeNode]<<endl;
        tree[treeNode] = value;
        return;
    }
    else
    {
        long long int mid = (start + end)/2;

        if(start <= index && index <= mid)
        {
            update(start,mid,2*treeNode,index,value);
        }
        else 
        {
            update(mid+1,end,2*treeNode+1,index,value);
        }

        tree[treeNode] = tree[2*treeNode + 1] + tree[2*treeNode];
    }

}

long long int query(long long int start,long long int end,long long int treeNode,long long int left,long long int right)
{
    if( start > right || end < left )
    {
        return 0;
    }

    if(start >= left && end <=right)
    {
        return tree[treeNode];
    }

    long long int mid = (start + end)/2;

    long long int ans1 = query(start,mid,2*treeNode,left,right);
    long long int ans2 = query(mid+1,end,2*treeNode+1,left,right);

    return ans1+ans2;

}

void printTree(long long int n)
{
    cout<<endl;
    for(int i = 0; i < 2*n; i++)
        cout<<tree[i]<<" ";
    cout<<endl;
}

int main() {

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        long long int val;
        cin >> val;
        arr[i] = ( (val % 2) == 0 )?1:0;
    }

    buildTree(1,n,1);
    // printTree(n);
    
    int k;
    cin >> k;

    for(int i = 0; i < k ; i++)
    {
        long long int a,b,c;
        cin >> a >> b >> c;
        if(a == 0)
        {
            if(c % 2 == 0)
            {
                c = 1;
            }
            else
            {
                c = 0;
            }
            update(1,n,1,b,c);
            // printTree(n);
        }
        else if(a == 1)
        {
            cout<<query(1,n,1,b,c)<<endl;
        }
        else if(a == 2)
        {

            cout<<c-b+(c!=b?1:0)-query(1,n,1,b,c)<<endl;
        }

    }

    return 0;
}