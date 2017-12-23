#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long dp[1002][8192];

vector<bool> sieve()
{
    vector<bool> boolSieve(9000);
    boolSieve[0] = false;
    boolSieve[1] = false;
    for(int i = 2; i < 9000 ; i++)
        boolSieve[i] = true;

    for(int i = 2; i*i < 9000; i++)
    {
        if(boolSieve[i])
        {
            for(int j = i*i; j < 9000; j += i)
            {
                boolSieve[j] = false;
            }
        }
    }

    return boolSieve;
}

long long primeXOR(int *arr,vector<bool> boolSieve,int n)
{
    memset(dp,0,sizeof(dp));
    dp[0][0] = (arr[0]+2)/2;
    dp[0][3500] = (arr[0]+1)/2;

    for(int i = 1; i < 1001; i++)
    {
        for(int j = 0; j < 8192; j++)
        {
            dp[i][j] = ( (dp[i-1][j] * ((2+arr[i])/2) ) + (dp[i-1][j^(3500+i)] * ((arr[i]+1)/2) ) ) %MOD;
        }
    }
    long long res = 0;

    for(int i = 2; i < 8192; i++)
    {
        if(boolSieve[i])
        {
            res = (res%MOD + dp[1000][i]%MOD)%MOD;
        }
    }
    
    return res;
}

int main()
{
    int q;
    cin >> q;
    vector<bool> bs = sieve();

    while(q--)
    {
        int n;
        cin >> n;
        int *arr = new int[1002];
        memset(arr,0,sizeof(arr));

        for(int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            arr[val-3500]++;
        }
        cout<<primeXOR(arr,bs,n)<<endl;
    }
    
    return 0;
}
