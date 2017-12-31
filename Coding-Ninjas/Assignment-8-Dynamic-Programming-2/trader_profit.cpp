#include <bits/stdc++.h>
using namespace std;

int dp[31][10][2];

int maximumProfit(int *price,int n,int k,int ongoing)
{
    if(dp[n][k][ongoing] != -1)
    {
        return dp[n][k][ongoing];
    }

    if(n == 0 || k == 0)
    {
        return 0;
    }
    //Ignore
    int ans1 = maximumProfit(price+1,n-1,k,ongoing);
    int ans2 = INT_MIN,ans3 = INT_MIN;

    //Sell
    if(ongoing)
    {
        ans2 = maximumProfit(price+1,n-1,k-1,0) + price[0];
    }
    else
    {
        if(k > 0)
        {   
            //Buy
            ans3 = maximumProfit(price+1,n-1,k,1) - price[0];
        }
        else
        {
            return INT_MIN;
        }
    }
    
    dp[n][k][ongoing] = max(ans3,max(ans1,ans2));
    return dp[n][k][ongoing];
}

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n,k;
        cin >> k >> n;
        int *price = new int[n];

        for(int i = 0; i < n; i++)
            cin >> price[i];

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }

        cout<<maximumProfit(price,n,k,0)<<endl;

        // for(int i = 0; i <= n; i++)
        // {
        //     for(int j = 0; j <= k; j++)
        //     {
        //         cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<"\t";
        //     }
        //     cout<<endl;
        // }

    }
    return 0;
}
