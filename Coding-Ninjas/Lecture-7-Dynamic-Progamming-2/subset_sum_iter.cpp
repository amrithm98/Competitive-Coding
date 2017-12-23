#include<bits/stdc++.h>
using namespace std;

bool subsetSumIter_Extended(int *arr,int n,int sum)
{
    bool **dp = new bool*[2];
    for(int i = 0; i <= 1; i++)
        dp[i] = new bool[sum+1];

    for(int i = 0; i <= sum; i++)
        dp[0][i] = false;

    dp[0][0] = true;
    int flag = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum ; j++)
        {
            dp[flag][j] = dp[flag^1][j];

            if(j >= arr[i-1])
            {
                dp[flag][j] = dp[flag][j] || dp[flag^1][j-arr[i-1]];
            }
        }
        flag = flag^1;
    }

    bool ans = dp[flag^1][sum];
    for(int i = 0; i <= 1; i++)
        delete [] dp[i];
    delete [] dp;
    return ans;

}

bool subsetSumIter(int *arr,int n,int sum)
{
    bool **dp = new bool*[n+1];
    for(int i = 0; i <= n; i++)
        dp[i] = new bool[sum+1];

    for(int i = 0; i <= sum; i++)
        dp[0][i] = false;
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum ; j++)
        {
            dp[i][j] = dp[i-1][j];

            if(j >= arr[i-1])
            {
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }

    bool ans = dp[n][sum];
    for(int i = 0; i <= n; i++)
        delete [] dp[i];
    delete [] dp;
    return ans;

}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int sum;
    cin >> sum;

    bool sol = subsetSumIter_Extended(arr,n,sum);
    if(sol)
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}