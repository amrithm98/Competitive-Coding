#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Write your code here
    int n;
    cin >> n;

    int *arr = new int[n+1];
    int *sum = new int[n+1];

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    sum[1] = arr[1];
    for(int i = 2; i <= n; i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }

    int **dp = new int*[n+1];
    int *freq = new int[100001];

    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[100001];
        for(int j = 0; j < 100001; j++)
        {
            dp[i][j] = 0;
            freq[j] = 0;
        }
    }

    unordered_set<int> s;
    for(int i = 1; i <= n; i++)
    {   
        int temp = 0;
        for(int j = 1; j < i; j++)
            temp += arr[j];

        s.insert(temp);
        for(int j = i; j <= n; j++)
        {
            temp = temp - arr[j-i]+arr[j];
            s.insert(temp);
        }
    }

    int max_freq = INT_MIN;
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(auto j : s)
        {
            dp[i][j] = dp[i-1][j];
            for(int k = i-1; k >= 0; k--)
            {
                if(sum[i-1]-sum[k] == j-arr[i])
                {
                    dp[i][j] = max(dp[i][j],dp[k][j]+1);
                    break;
                }
            }

            freq[j] = max(freq[j],dp[i][j]);
            max_freq = max(max_freq,freq[j]);
        }
    }

    cout << max_freq << endl;
    for(int i = 0; i < 100000; i++)
    {
        if(freq[i] == max_freq)
            cout << i << " ";
    }

    return 0;
}