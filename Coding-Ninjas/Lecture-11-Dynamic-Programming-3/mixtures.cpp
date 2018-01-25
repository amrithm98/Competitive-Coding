#include <bits/stdc++.h>
using namespace std;

int colSum(vector<int> colors,int i,int j)
{
    int sum = 0;
    for(int k = i; k <= j; k++)
    {
        sum = (sum + colors[k])%100;
    }
    return sum;
}
int mixtures(vector<int> colors, int **dp,int i ,int j)
{
    if(i == j)
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int minSmoke = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int pos = mixtures(colors,dp,i,k) + mixtures(colors,dp,k+1,j) + colSum(colors,i,k)*colSum(colors,k+1,j);
        minSmoke = min(minSmoke,pos);
    }
    dp[i][j] = minSmoke;

    return minSmoke;
}

int solve(int n,vector<int>colors)
{
	// Write your code here .
    int **dp = new int*[n];
    for(int i = 0; i < n; i++)
    {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    int ans = mixtures(colors,dp,0,n-1);
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> cols(n);
    for(int i = 0;i < n; i++)
    {
        cin >> cols[i];
    }
    cout << solve(n,cols) << endl;
    return 0;
}