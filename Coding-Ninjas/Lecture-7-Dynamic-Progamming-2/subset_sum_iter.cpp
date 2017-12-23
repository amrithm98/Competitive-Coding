#include<bits/stdc++.h>
using namespace std;

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

    bool sol = subsetSumIter(arr,n,sum);
    if(sol)
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}