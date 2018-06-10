#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define LL long long int

struct Node
{
    LL squareSum;
    LL sum;
};

struct LazyNode
{
    LL value;
    int type;
};

long long arr[MAX];
Node tree[3*MAX];
LazyNode lazyTree[3*MAX];

void printTree(int n)
{
    cout << "\nSEGMENT TREE : \n";
    for(int i = 0; i < 2*n; i++)
    {
        cout << tree[i].sum << " ";
    }
    cout << endl;
    for(int i = 0; i < 2*n; i++)
    {
        cout << tree[i].squareSum << " ";
    }
    cout << endl;

    cout << "\nLazy TREE : \n";
    for(int i = 0; i < 2*n; i++)
    {
        cout << lazyTree[i].value << " ";
    }
    cout << endl;
    for(int i = 0; i < 2*n; i++)
    {
        cout << lazyTree[i].type << " ";
    }
    cout << endl;
}

void buildTree(int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode].squareSum = arr[start]*(LL)arr[start];
        tree[treeNode].sum = (LL)arr[start];

        lazyTree[treeNode].type = 0;
        lazyTree[treeNode].value = 1001;

        return;
    }

    int mid = (start + end)/2;
    buildTree(start,mid,2*treeNode+1);
    buildTree(mid+1,end,2*treeNode+2);

    tree[treeNode].sum = tree[2*treeNode+1].sum + tree[2*treeNode+2].sum;
    tree[treeNode].squareSum = tree[2*treeNode+1].squareSum + tree[2*treeNode+2].squareSum;

    lazyTree[treeNode].value = 1001;
    lazyTree[treeNode].type = 0;
}

void updateIncrement(int start,int end,int treeNode,int startR,int endR,LL value)
{
    if(lazyTree[treeNode].type != 0)
    {
        if(lazyTree[treeNode].type == 1)
        {
            LL lazyval = lazyTree[treeNode].value;
            tree[treeNode].squareSum += (end-start+1)*(lazyval*lazyval) + 2*lazyval*tree[treeNode].sum;
            tree[treeNode].sum += (end-start+1)*lazyval;
        }
        else if(lazyTree[treeNode].type == 2)
        {
            tree[treeNode].squareSum = (end-start+1)*(lazyTree[treeNode].value)*(lazyTree[treeNode].value);
            tree[treeNode].sum = (end-start+1)*lazyTree[treeNode].value;
        }

        if(start != end)
        {
            lazyTree[2*treeNode+1].value = lazyTree[treeNode].value;
            lazyTree[2*treeNode+2].value = lazyTree[treeNode].value;

            lazyTree[2*treeNode+1].type = lazyTree[treeNode].type;
            lazyTree[2*treeNode+2].type = lazyTree[treeNode].type;
        }

        lazyTree[treeNode].value = 1001;
        lazyTree[treeNode].type = 0;
    }
    

    if(start > end || start > endR || end < startR)
    {
        return;
    }

    if(start >= startR && end <= endR)
    {
        tree[treeNode].squareSum += (end-start+1)*value*value + 2*value*tree[treeNode].sum;
        tree[treeNode].sum += (end-start+1)*value;

        if(start != end)
        {
            lazyTree[2*treeNode+1].value = value;
            lazyTree[2*treeNode+2].value = value;

            lazyTree[2*treeNode+1].type = 1;
            lazyTree[2*treeNode+2].type = 1;
        }

        return;
    }

    int mid = (start+end)/2;
    updateIncrement(start,mid,2*treeNode+1,startR,endR,value);
    updateIncrement(mid+1,end,2*treeNode+2,startR,endR,value);

    tree[treeNode].sum = tree[2*treeNode+1].sum + tree[2*treeNode+2].sum;
    tree[treeNode].squareSum = tree[2*treeNode+1].squareSum + tree[2*treeNode+2].squareSum;
}

void updateChange(int start,int end,int treeNode,int startR,int endR,LL value)
{
    if(lazyTree[treeNode].type != 0)
    {
        if(lazyTree[treeNode].type == 1)
        {
            LL lazyval = lazyTree[treeNode].value;
            tree[treeNode].squareSum += (end-start+1)*(lazyval*lazyval) + 2*lazyval*tree[treeNode].sum;
            tree[treeNode].sum += (end-start+1)*lazyval;
        }
        else if(lazyTree[treeNode].type == 2)
        {
            tree[treeNode].squareSum = (end-start+1)*(lazyTree[treeNode].value)*(lazyTree[treeNode].value);
            tree[treeNode].sum = (end-start+1)*lazyTree[treeNode].value;
        }

        if(start != end)
        {
            lazyTree[2*treeNode+1].value = lazyTree[treeNode].value;
            lazyTree[2*treeNode+2].value = lazyTree[treeNode].value;

            lazyTree[2*treeNode+1].type = lazyTree[treeNode].type;
            lazyTree[2*treeNode+2].type = lazyTree[treeNode].type;
        }
        lazyTree[treeNode].value = 1001;
        lazyTree[treeNode].type = 0;
    }
    

    if(start > end || start > endR || end < startR)
    {
        return;
    }

    if(start >= startR && end <= endR)
    {
        tree[treeNode].squareSum = (end-start+1)*value*value;
        tree[treeNode].sum = (end-start+1)*value;

        if(start != end)
        {
            lazyTree[2*treeNode+1].value = value;
            lazyTree[2*treeNode+2].value = value;

            lazyTree[2*treeNode+1].type = 2;
            lazyTree[2*treeNode+2].type = 2;
        }

        return;
    }

    int mid = (start+end)/2;
    updateChange(start,mid,2*treeNode+1,startR,endR,value);
    updateChange(mid+1,end,2*treeNode+2,startR,endR,value);

    tree[treeNode].sum = tree[2*treeNode+1].sum + tree[2*treeNode+2].sum;
    tree[treeNode].squareSum = tree[2*treeNode+1].squareSum + tree[2*treeNode+2].squareSum;
}

LL query(int start,int end,int treeNode,int startR,int endR)
{
    if(start > end || start > endR || end < startR)
    {
        return 0;
    }
    
    if(lazyTree[treeNode].type != 0)
    {
        if(lazyTree[treeNode].type == 1)
        {
            int lazyval = lazyTree[treeNode].value;
            tree[treeNode].squareSum += (end-start+1)*(lazyval*lazyval) + 2*lazyval*tree[treeNode].sum;
            tree[treeNode].sum += (end-start+1)*lazyval;
        }
        else if(lazyTree[treeNode].type == 2)
        {
            tree[treeNode].squareSum = (end-start+1)*(lazyTree[treeNode].value)*(lazyTree[treeNode].value);
            tree[treeNode].sum = (end-start+1)*lazyTree[treeNode].value;
        }

        if(start != end)
        {
            lazyTree[2*treeNode+1].value = lazyTree[treeNode].value;
            lazyTree[2*treeNode+2].value = lazyTree[treeNode].value;

            lazyTree[2*treeNode+1].type = lazyTree[treeNode].type;
            lazyTree[2*treeNode+2].type = lazyTree[treeNode].type;
        }
        lazyTree[treeNode].value = 1001;
        lazyTree[treeNode].type = 0;
    }

    if(start >= startR && end <= endR)
    {
        return tree[treeNode].squareSum;
    }

    int mid = (start+end)/2;

    LL ans1 = query(start,mid,2*treeNode+1,startR,endR);
    LL ans2 = query(mid+1,end,2*treeNode+2,startR,endR);

    return ans1+ans2;
}

int main()
{
    int t;
    cin >> t;

    int k = 1;
    while(k <= t)
    {
        int n,q;
        cin >> n >> q;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        buildTree(0,n-1,0);
        // printTree(n);
        cout << "Case " << k << ":" << endl;
        for(int i = 1; i <= q; i++)
        {
            int op;
            cin >> op;

            int st,nd;
            cin >> st >> nd;
            
            st--;
            nd--;

            if(op == 2)
            {
                LL ans = query(0,n-1,0,st,nd);
                cout << ans << endl;
            }
            else if(op == 1)
            {
                LL val;
                cin >> val;
                updateIncrement(0,n-1,0,st,nd,val);
            }
            else if(op == 0)
            {
                LL val;
                cin >> val;
                updateChange(0,n-1,0,st,nd,val);
            }
            // printTree(n);
        }

        k++;
    }
    return 0;
}