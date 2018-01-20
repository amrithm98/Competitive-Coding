#include<bits/stdc++.h>
using namespace std;
#define LL long long int 

struct node {
    LL squareSum;
    LL sum;
}zero;

node *tree;
int *arr,*lazyInc,*lazyChange;

void buildTree(int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode].sum = arr[start];
        tree[treeNode].squareSum = arr[start]*arr[start];

        lazyInc[treeNode] = 0;
        lazyChange[treeNode] = 0;

        return;
    }

    int mid = (start + end)/2;

    buildTree(start,mid,2*treeNode);
    buildTree(mid+1,end,2*treeNode+1);

    tree[treeNode].sum = tree[2*treeNode].sum + tree[2*treeNode+1].sum;
    tree[treeNode].squareSum = tree[2*treeNode].squareSum + tree[2*treeNode+1].squareSum;

}

void printTree(int n)
{
    cout<<endl;
    for(int i = 1; i < 2*n+3; i++)
    {
        cout << tree[i].sum << " ";
    }
    cout << endl;
    for(int i = 1; i < 2*n+3; i++)
    {
        cout << tree[i].squareSum << " ";
    }
    cout << endl;
    for(int i = 1; i < 2*n+3; i++)
    {
        cout << lazyInc[i] << " ";
    }
    cout << endl;
}

void updateIncrement(int start,int end,int startR,int endR,int inc,int treeNode)
{
    if(lazyInc[treeNode] != 0 )
    {
        int lazyValue = lazyInc[treeNode];
        tree[treeNode].sum += ( (lazyValue*lazyValue*(end-start+1)) + 2*lazyValue*tree[treeNode].sum);
        tree[treeNode].sum += (end-start+1)*lazyValue;
        if(start != end)
        {
            lazyInc[2*treeNode] += lazyValue;
            lazyInc[2*treeNode+1] += lazyValue;
        }
        lazyInc[treeNode] = 0;
    }   
  
    if(lazyChange[treeNode] != 0 )
    {
        int lazyValue = lazyChange[treeNode];
        tree[treeNode].sum = lazyValue*lazyValue;
        tree[treeNode].sum = (end-start+1)*lazyValue;
        if(start != end)
        {
            lazyChange[2*treeNode] += lazyValue;
            lazyChange[2*treeNode+1] += lazyValue;
        }
        lazyChange[treeNode] = 0;
    }  

    if(start > end || start > endR || end < startR)
    {
        return;
    }

    if(start >= startR && end <= endR)
    {
        tree[treeNode].squareSum += ( (inc*inc*(end-start+1)) + 2*inc*tree[treeNode].sum);   
        tree[treeNode].sum += (end-start+1)*inc;
        if(start != end)
        {
            lazyInc[2*treeNode] += inc;
            lazyInc[2*treeNode+1] += inc;
        }
        return;
    }

    int mid = (start + end)/2;
    updateIncrement(start,mid,startR,endR,inc,2*treeNode);
    updateIncrement(mid+1,end,startR,endR,inc,2*treeNode+1);

    tree[treeNode].sum = tree[2*treeNode].sum + tree[2*treeNode+1].sum;
    tree[treeNode].squareSum = tree[2*treeNode].squareSum + tree[2*treeNode+1].squareSum;

    return;
}

void updateChange(int start,int end,int startR,int endR,int val,int treeNode)
{
    if(lazyChange[treeNode] != 0 )
    {
        int inc = lazyChange[treeNode];
        tree[treeNode].sum = inc*inc;
        tree[treeNode].sum = (end-start+1)*inc;
        if(start != end)
        {
            lazyChange[2*treeNode] += inc;
            lazyChange[2*treeNode+1] += inc;
        }
        lazyChange[treeNode] = 0;
    }   
  
    if(lazyInc[treeNode] != 0 )
    {
          int lazyValue = lazyInc[treeNode];
          tree[treeNode].sum += ( (lazyValue*lazyValue*(end-start+1)) + 2*lazyValue*tree[treeNode].sum);
          tree[treeNode].sum += (end-start+1)*lazyValue;
          if(start != end)
          {
              lazyInc[2*treeNode] += lazyValue;
              lazyInc[2*treeNode+1] += lazyValue;
          }
          lazyInc[treeNode] = 0;
    }  

    if(start > end || start > endR || end < startR)
    {
        return;
    }

    if(start >= startR && end <= endR)
    {
        tree[treeNode].squareSum = val*val*(end-start+1);  
        tree[treeNode].sum = (end-start+1)*val;
        if(start != end)
        {
            lazyChange[2*treeNode] += val;
            lazyChange[2*treeNode+1] += val;
        }
        return;
    }

    int mid = (start + end)/2;
    updateChange(start,mid,startR,endR,val,2*treeNode);
    updateChange(mid+1,end,startR,endR,val,2*treeNode+1);

    tree[treeNode].sum = tree[2*treeNode].sum + tree[2*treeNode+1].sum;
    tree[treeNode].squareSum = tree[2*treeNode].squareSum + tree[2*treeNode+1].squareSum;

    return;
}

node query(int start,int end,int startR,int endR,int treeNode)
{
    if(start > end)
    {
        return zero;
    }

    if(start > endR || end < startR)
    {
        return zero;
    }

    if(lazyChange[treeNode] != 0)
    {
        // cout<<"\nLazy Pending Change\n";
        int inc = lazyChange[treeNode];
        tree[treeNode].sum = inc*inc;
        tree[treeNode].sum = (end-start+1)*inc;
        if(start != end)
        {
            lazyChange[2*treeNode] += inc;
            lazyChange[2*treeNode+1] += inc;
        }
        lazyChange[treeNode] = 0;
    }

    if(lazyInc[treeNode] != 0)
    {
        // cout<<"\nLazy Pending Update\n";
        int lazyValue = lazyInc[treeNode];
        tree[treeNode].sum += ( (lazyValue*lazyValue*(end-start+1)) + 2*lazyValue*tree[treeNode].sum);
        tree[treeNode].sum += (end-start+1)*lazyValue;
        if(start != end)
        {
            lazyInc[2*treeNode] += lazyValue;
            lazyInc[2*treeNode+1] += lazyValue;
        }
        lazyInc[treeNode] = 0;
    }

    if(start >= startR && end <= endR)
    {
        // cout << "\nCOMPLETE: ";
        return tree[treeNode];
    }

    int mid = (start + end)/2;

    node ans1 = query(start,mid,2*treeNode,startR,endR);
    node ans2 = query(mid+1,end,2*treeNode+1,startR,endR);
    node ans3;
    ans3.sum = ans1.sum + ans2.sum;
    ans3.squareSum = ans1.squareSum + ans2.squareSum;
    return ans3;
}

int main()
{
    int t;
    cin >> t;
    zero = {0,0};
    int temp = 1;
    while(temp <= t)
    {
        int n,q;
        cin >> n >> q;

        arr = new int[n+1];
        tree = new node[3*n];
        lazyInc = new int[3*n];
        lazyChange = new int[3*n];

        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        buildTree(1,n,1);
        // printTree(n);
        cout<<"Case "<<temp<<":\n";
        for(int i = 1; i <= q; i++)
        {
            int op,st,nd,x;
            cin >> op >> st >> nd;
            if(op == 0)
            {
                cin >> x;
                updateChange(1,n,st,nd,x,1);
            }
            else if(op == 1)
            {
                cin >> x;
                updateIncrement(1,n,st,nd,x,1);
            }
            else if(op == 2)
            {
                node sol = query(1,n,st,nd,1);
                cout<<sol.squareSum<<endl;
            }
        }
        temp++;
    }
    return 0;
}