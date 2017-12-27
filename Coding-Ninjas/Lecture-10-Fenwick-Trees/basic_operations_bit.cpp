#include <bits/stdc++.h>
using namespace std;

void updateTree(int index,int value,int *BIT,int n)
{
    for(; index <= n; index += index&(-index))
    {
        BIT[index] += value;
    }
}

int query(int index, int *BIT)
{
    int sum = 0;
    for(; index > 0; index -= index&(-index))
    {
        sum += BIT[index];
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n+1]();
    int *BIT = new int[n+1]();
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        updateTree(i,arr[i],BIT,n);
    }

    int q;
    cin >> q;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        cout<<query(b,BIT) - query(a-1,BIT) << endl;
    }
}