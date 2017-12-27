#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int maximum;
    int second_maximum;
};

void buildTree(int *arr,node *tree,int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode].maximum = arr[start];
        tree[treeNode].second_maximum = INT_MIN;
        return ;
    }

    int mid = (start + end)/2;

    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode + 1);

    node left = tree[2*treeNode];
    node right = tree[2*treeNode + 1];

    tree[treeNode].maximum = max(left.maximum,right.maximum);
    tree[treeNode].second_maximum = min(max(right.second_maximum,left.maximum),max(right.maximum,left.second_maximum));
    
    return;
}

void update(int *arr,node *tree,int start,int end,int treeNode,int index,int value)
{
    if(start == end)
    {
        tree[treeNode].maximum = value;
        tree[treeNode].second_maximum = INT_MIN;
        return ;
    }
    else
    {
        int mid = (start + end)/2;
        if(index > mid)
        {
            update(arr,tree,mid+1,end,2*treeNode + 1,index,value);
        }
        else
        {
            update(arr,tree,start,mid,2*treeNode,index,value);
        }
        node left = tree[2*treeNode];
        node right = tree[2*treeNode + 1];
        
        tree[treeNode].maximum = max(left.maximum,right.maximum);
        tree[treeNode].second_maximum = min(max(right.second_maximum,left.maximum),max(right.maximum,left.second_maximum));
    
        return;
    }
}

node query(int *arr,node *tree,int start,int end,int treeNode,int left,int right)
{
    if(start > right || end < left)
    {
        node zero;
        zero.maximum = INT_MIN;
        zero.second_maximum = INT_MIN;
        return zero;
    }
    if(start >= left && end <= right)
    {
        return tree[treeNode];
    }
    int mid = (start + end)/2;
    node q1 = query(arr,tree,start,mid,2*treeNode,left,right);
    node q2 = query(arr,tree,mid+1,end,2*treeNode + 1,left,right);
    node q3;
    q3.maximum = max(q1.maximum,q2.maximum);
    q3.second_maximum = min(max(q2.second_maximum,q1.maximum),max(q2.maximum,q1.second_maximum));

    return q3;
}

void printTree(node *tree,int n)
{
    cout<<endl;
    for(int i = 0; i < 3*n; i++)
    {
        cout<<tree[i].maximum<<" , "<<tree[i].second_maximum<<endl;
    }
    cout<<endl;
}

int main() {

    int n;
    cin >> n;

    int *arr = new int[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    node *tree = new node[3*n];

    buildTree(arr,tree,1,n,1);
    // printTree(tree,n);

    int q;
    cin >> q;

    while(q--)
    {
        char a;
        int b,c;
        cin >> a >> b >> c;
        if(a == 'Q')
        {   
            node ans = query(arr,tree,1,n,1,b,c);
            cout<<ans.maximum + ans.second_maximum<<endl;
        }
        else if(a == 'U')
        {
            update(arr,tree,1,n,1,b,c);
        }
    }

    return 0;
}