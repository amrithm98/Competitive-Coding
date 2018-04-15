#include <bits/stdc++.h>
using namespace std;

struct Node
{
    long long curr;
    long long exp;
    int index;
};

struct Tree
{
    long long mn;
    long long mx;
};


Node arr[100005];
Tree tree[400005];

bool compare(Node a,Node b)
{
    if(a.exp == b.exp)
    {
        return a.index < b.index;
    }
    else
        return a.exp > b.exp;
}


void buildTree(int start,int end,int treeNode)
{
    if(start == end)
    {
        //Maximum of Expected Value & Minimum of Current Value
        tree[treeNode].mx = arr[start].exp;
        tree[treeNode].mn = arr[start].curr;
        return;
    }

    int mid = (start+end)/2;

    buildTree(start,mid,2*treeNode+1);
    buildTree(mid+1,end,2*treeNode+2);

    tree[treeNode].mn = min(tree[2*treeNode+1].mn,tree[2*treeNode+2].mn);
    tree[treeNode].mx = max(tree[2*treeNode+1].mx,tree[2*treeNode+2].mx);
}

void printTree(int n)
{
    cout << "\nTREE: \n";

    for(int i = 0; i < 2*n; i++)
        cout << tree[i].mx << " ";

    cout << endl;

    for(int i = 0; i < 2*n; i++)
        cout << tree[i].mn << " ";

}

long long minQuery(int start,int end,int left,int right,int treeNode)
{
    if(left > end || right < start)
    {
        return LLONG_MAX;
    }

    if(start >= left && end <= right)
    {
        return tree[treeNode].mn;
    }
    int mid = (start+end)/2;

    return min(minQuery(start,mid,left,right,2*treeNode+1),minQuery(mid+1,end,left,right,2*treeNode+2));
}

long long maxQuery(int start,int end,int left,int right,int treeNode)
{
    if(left > end || right < start)
    {
        return 0;
    }
    if(start >= left && end <= right)
    {
        return tree[treeNode].mx;
    }
    int mid = (start+end)/2;

    return max(maxQuery(start,mid,left,right,2*treeNode+1),maxQuery(mid+1,end,left,right,2*treeNode+2));
}

long long minCutReq(int n)
{
    buildTree(0,n-1,0);
    sort(arr,arr+n,compare);
    // printTree(n);
    int cutNeeded = 0;
    int i = 0;

    while(i < n)
    {
        if(arr[i].curr == arr[i].exp)
        {
            i++;
            continue;
        }

        int j = i+1;
        int cc = 1;

        while(j < n && arr[j].exp == arr[i].exp)
        {
            long long big = maxQuery(0,n-1,arr[j-1].index,arr[j].index,0);
            long long small = minQuery(0,n-1,arr[j-1].index,arr[j].index,0);
            // cout << big << " " << small << endl;
            if(big > arr[i].exp || small < arr[i].exp)
            {
                if(cc > 0)
                    cutNeeded++;
                cc = 0;
            }
            
            if(arr[j].curr != arr[j].exp)
                cc++;

            j++;
        }

        i = j;

        if(cc > 0)
            cutNeeded++;

    }
    
    return cutNeeded;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;   
        bool flag = false;

        for(int i = 0; i < n; i++)
            cin >> arr[i].curr;

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i].exp;
            arr[i].index = i;

            if(arr[i].curr < arr[i].exp)
            {
                flag = true;
            }
        }

        if(flag)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            cout << minCutReq(n) << endl;
        }
       
    }

    return 0;
}