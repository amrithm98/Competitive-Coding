#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool subsetSum(int *arr,int n,int k)
{
    if(dp[n][k] >= 0)
        return dp[n][k];

    if(k == 0)
    {
        dp[n][k] = 1;
        return 1;
    }
    
    if(k < 0)
    {
        return 0;
    }

    if(n == 0 && k != 0)
    {
        return 0;
    }

    bool ans1 = subsetSum(arr+1,n-1,k-arr[0]);
    bool ans2 = subsetSum(arr+1,n-1,k);

    dp[n][k] = ans1 || ans2;

    return dp[n][k];

}

int main()
{
    int n,k;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i]; 

    cin >> k;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = -1;

    int ans = subsetSum(arr,n,k);
    if(ans)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;   
}
