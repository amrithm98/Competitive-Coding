#include<bits/stdc++.h>
using namespace std;

int knapsack(int *weights,int *values,int W,int n,int **dp)
{
    if(n == 0 || W == 0)
    {
        return 0;
    }
    if(dp[n][W] > -1)
        return dp[n][W];
    else
    {

        if(weights[n-1] > W)
            dp[n][W] = knapsack(weights,values,W,n-1,dp);
        else
        {
            dp[n][W] = max(knapsack(weights,values,W,n-1,dp),values[n-1] + knapsack(weights,values,W-weights[n-1],n-1,dp));
        }
    }
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

    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[W+1];
        for(int j = 0; j <= W ; j++)
            dp[i][j] = -1;
    }
    knapsack(weights,values,W,n,dp);
    cout<<dp[n][W]<<endl;
}