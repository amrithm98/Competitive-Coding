#include<bits/stdc++.h>
using namespace std;

int knapsack(int *weights,int *values,int W,int n)
{
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[W+1];
    }
    for(int i = 0; i <= W ; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n ; i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n ; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            dp[i][w] = dp[i-1][w];
            if(weights[i-1] <= w)
                dp[i][w] = max(dp[i][w],values[i-1] + dp[i-1][w-weights[i-1]]);
        }
    }
    return dp[n][W];
}

int main()
{
    int n,W;
    cin >> n; 

    int *weights = new int[n];
    int *values = new int[n];

    for(int i = 0; i < n ; i++)
        cin >> weights[i];
    for(int i = 0; i < n ; i++)
        cin >> values[i];   

    cin >> W;
    
    int ans = knapsack(weights,values,W,n);
    cout<<ans<<endl;
}