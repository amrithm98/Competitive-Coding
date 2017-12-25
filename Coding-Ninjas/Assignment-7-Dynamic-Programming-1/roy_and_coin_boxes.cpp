#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int startQuery[MAX],endQuery[MAX];

int main()
{

    int n,m,q;
    cin >> n;
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int l,r;
        cin >> l >> r;
        startQuery[l]++;
        endQuery[r]++;
    }

    cin >> q;

    int *queries = new int[q];
    for(int i = 0; i < q; i++)
        cin >> queries[i];

    int *arr = new int[n+1];
    arr[1] = startQuery[1];

    for(int i = 2; i <= n; i++)
    {
        //Count of entries in Box i
        arr[i] = arr[i-1] + startQuery[i] - endQuery[i-1];
    }

    int *dp = new int[n+1];
    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= n; i++)
    {
        //Count of Values..ie frequency of each value
        dp[arr[i]]++;
    }

    for(int i = n; i >= 2; i--)
    {
        //Atleast DP Array
        dp[i-1] += dp[i];
    }

    for(int i = 0; i < q; i++)
    {
        if(queries[i] > n)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<dp[queries[i]]<<endl;
        }
    }

    return 0;
}
