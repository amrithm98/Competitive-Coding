#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

struct node
{
    int val;
    int len;
}zero;

node *tree;
string bin;

int power(int n)
{
    if(n % 2 == 0)
        return 1;
    else 
        return 2;
}

void buildTree(int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode].val = bin[end]-'0';
        tree[treeNode].len = 1;
        return ;
    }

    int mid = (start + end)/2;

    buildTree(start,mid,2*treeNode);
    buildTree(mid+1,end,2*treeNode+1);

    tree[treeNode].val = ( tree[2*treeNode+1].val +  (tree[2*treeNode].val)*(int)pow(2,(tree[2*treeNode+1].len)%2))%3;
    tree[treeNode].len = (tree[2*treeNode+1].len + tree[2*treeNode].len);
    return;
}

void update(int start,int end,int treeNode,int index,int value)
{
    if(start == end)
    {
        tree[treeNode].val = value;
        tree[treeNode].len = 1;
        return;
    }

    int mid = (start + end)/2;
    if(index <= mid)
    {
        update(start,mid,2*treeNode,index,value);
    }
    else
    {
        update(mid+1,end,2*treeNode+1,index,value);
    }

    tree[treeNode].val = ( tree[2*treeNode+1].val +  (tree[2*treeNode].val)*(int)pow(2,(tree[2*treeNode+1].len)%2))%3;
    tree[treeNode].len = (tree[2*treeNode+1].len + tree[2*treeNode].len);
    return;
}

node query(int start,int end,int treeNode,int left,int right)
{
    if(start > right || end < left)
    {
       return zero;
    }

    if(start >= left && end <=right)
    {
        return tree[treeNode];
    }

    int mid = (start+end)/2;

    node ans1 = query(start,mid,2*treeNode,left,right);
    node ans2 = query(mid+1,end,2*treeNode+1,left,right);
    
    node ans3;
    ans3.val =  (ans2.val + ans1.val*(int)pow(2,(ans2.len)%2))%3;
    ans3.len = (ans1.len + ans2.len);

    return ans3;
}

void printTree(int n)
{
    cout<<"\nTREE: ";
    for(int i = 1; i < 2*n; i++)
    {
        cout<<tree[i].val<<" ";
    }
}

int main()
{
    int n;
    cin >> n;
    cin >> bin;
    tree = new node[4*n];
    buildTree(0,n-1,1);
    // printTree(n);
    zero.val = 0;
    zero.len = 0;
    int q;
    cin >>q ;

    while(q--)
    {
        int o;
        cin >> o;

        if(o == 0)
        {
            int l,r;
            cin >> l >> r;
            node ans = query(0,n-1,1,l,r);
            cout<<ans.val<<endl;
        }
        else
        {
            int i;
            cin >> i;
            update(0,n-1,1,i,1);
            // printTree(n);
        }
    }

    return 0;
}