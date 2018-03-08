#include <bits/stdc++.h>
using namespace std;


long long solve(int like[][20],int N)
{
	// Write your code here.
    long long dp[(1 << N)];
    memset(dp,0,sizeof(dp));
    dp[(1<<N)-1] = 1;

    for(int mask = (1 << N) - 2; mask >= 0; mask-- )
    {
        int temp = mask;
        int k = 0;
        while(temp > 0)
        {
            int lastBit = temp & 1;
            k += lastBit;
            temp /= 2;
        }

        for(int i = 0; i < N; i++)
        {
            if(like[k][i] && !(mask & (1 << i)))
            {
                dp[mask] += dp[mask | (1 << i)];
            }   
        }
    }
    // for(int i = 0; i < N; i++)
    //     cout << dp[i] << " ";
    return dp[0];
}

int main()
{
    int n;
    cin >> n;

    int like[20][20];

    for(int i = 0;i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> like[i][j];
        }
    }

    cout << solve(like,n) << endl;
    return 0;
}