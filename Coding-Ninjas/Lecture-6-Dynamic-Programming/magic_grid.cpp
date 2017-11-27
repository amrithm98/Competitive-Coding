#include <bits/stdc++.h>
using namespace std;

int min_health(int **input,int n,int m)
{
    int **dp = new int*[n];
    for(int i = 0; i < n; i++)
        dp[i] = new int[m];
    dp[n-1][m-1] = 1;
    dp[n-2][m-1] = 1;   //Top of bottom most
    dp[n-1][m-2] = 1;   //Left of bottom most

    for(int i = n-2 ; i >= 0; i--)
    {
       dp[i][m-1] = max(1,dp[i+1][m-1]-input[i+1][m-1]);
    }
    for(int j =  m-2; j >= 0 ; j--)
    {
        dp[n-1][j] = max(1,dp[n-1][j+1] - input[n-1][j+1]);
    }
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = m-2; j >= 0; j--)
        {
            dp[i][j] = max(1,min(dp[i+1][j]-input[i+1][j],dp[i][j+1] - input[i][j+1]));
        }
    }
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return dp[0][0];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int **input = new int*[n];
        for(int i = 0; i < n; i++)
            input[i] = new int[m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> input[i][j];
        int result = min_health(input,n,m);
        cout<<result<<endl;
    }
    return 0;
}
