#include<bits/stdc++.h>
using namespace std;

int knapsack_optim(int *weights,int *values,int n,int maxWeight)
{
    int *dp[2];
        dp[0] = new int[maxWeight+1];
        dp[1] = new int[maxWeight+1];
    for(int i = 0; i <= maxWeight ; i++)
    {
        dp[0][i] = 0;
    }   
    dp[1][0] = 0;
    bool k = 1;
    int w;
    for(int i = 1; i <= n ; i++ , k=!k)
    {
        w = 0;
        while(w < weights[i-1])
        {
            dp[k][w] = dp[!k][w];
            w++;
        }
        while(w <= maxWeight){
            dp[k][w] = max(dp[!k][w],values[i-1] + dp[!k][w-weights[i-1]]);
            w++;
        }
    }
    return dp[!k][maxWeight];
}

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
        int w;
        for(w = 0; w < weights[i-1]; w++)
        {
            dp[i][w] = dp[i-1][w];
            // if(weights[i-1] <= w)
            //     dp[i][w] = max(dp[i][w],values[i-1] + dp[i-1][w-weights[i-1]]);
        }
        for(; w<=W ; w++){
            dp[i][w] = dp[i-1][w];
            // if(weights[i-1] <= w)
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