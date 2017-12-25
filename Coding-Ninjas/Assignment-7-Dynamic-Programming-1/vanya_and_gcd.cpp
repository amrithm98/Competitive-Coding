#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int arr[501];

int gcd(int a,int b)
{
    if(a<b)
        return gcd(b,a);

    if(b == 0)
        return a;

    else
        return gcd(b,a%b);

}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    long long dp[n][101];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= 100; j++)
            dp[i][j] = 0;
    }

    dp[0][arr[0]] = 1;
    long long sum = dp[0][1];

    for(int i = 1; i < n; i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            if(arr[j] < arr[i])
            {
                for(int k = 1; k <= 100; k++)
                {
                    int ng = gcd(arr[i],k);
                    dp[i][ng] = (dp[i][ng] + dp[j][k])%MOD;
                }
            }
        }
        dp[i][arr[i]]++;
        sum = (sum + dp[i][1])%MOD;
    }

    cout<<sum<<endl;

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j <= 10; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    
    return 0;
}
