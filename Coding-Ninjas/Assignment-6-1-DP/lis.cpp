#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n) 
{
    int *dp = new int[n+1];

    for(int i = 0; i <= n; i++)
        dp[i] = 1;

    dp[0] = 1;

    for(int i = 1; i < n; i++)
    {
        int elem = arr[i];
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[j] < elem)
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }

    int mx = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        // cout << dp[i] << " ";

        if(dp[i] > mx)
            mx = dp[i];
    }

    return mx;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << lis(arr,n) << endl;

    return 0;
}