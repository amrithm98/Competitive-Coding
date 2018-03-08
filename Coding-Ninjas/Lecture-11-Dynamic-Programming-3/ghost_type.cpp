#include <bits/stdc++.h>
using namespace std;

vector<int> andRes[30];
vector<long long> dp(1<<21);

long long solve(int mask,int n)
{
    if(dp[mask] != -1LL)
        return dp[mask];

    if(mask == (1 << n) -1)
    {
        return 1;
    }

    for(int i = 0; i < n; i++)
    {
        if(! (mask & (1 << i)) )
        {
            //If ith bit is not set
            
        }
    }
    return dp[mask];
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++ )
        {
            if( (i & j) == i)
            {
                andRes[i].push_back(j);
            }
        }
    }
    for(int i = 0; i <= (1<<n); i++)
        dp[i] = -1;
    
    cout << solve(0,n) << endl;

    return 0;
}

