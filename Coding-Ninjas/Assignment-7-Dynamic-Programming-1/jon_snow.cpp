#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x;
    cin >> n >> k >> x;

    int *arr = new int[1001];
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[a]++;
    }
    int *dp = new int[1001];

    int traversed_count = 0;
    int max = 0;
    int min = INT8_MAX;

    for(int i = 0; i <= 1000; i++)
        dp[i] = arr[i];

    for(int j = 0; j < k; j++)
    {
        for(int i = 0; i <= 1000; i++)
        {
            if(arr[i] != 0)
            {
                if(traversed_count % 2 == 0)
                {
                    int change = (arr[i]+1)/2;
                    dp[i^x] += change;
                    dp[i] = (arr[i] - change);
                }

                else
                {
                    int change = (arr[i]/2);
                    dp[i^x] += change;
                    dp[i] = (arr[i] - change);
                }
                traversed_count += arr[i];
                // cout<<i<<" "<<dp[i]<<" "<<(i^x)<<" "<<dp[i^x]<<endl;
            }
        }

        for(int i = 0; i <= 1000; i++)
            arr[i] = dp[i];

        memset(dp,0,sizeof(dp));

        traversed_count = 0;
    }
    for(int i = 0; i <= 1000; i++)
    {
        if(arr[i] != 0)
        {
            min = i;
            break;
        }
    }

    for(int i = 1000; i >= 0; i--)
    {
        if(arr[i] != 0)
        {
            max = i;
            break;
        }
    }

    cout<<max<<" "<<min<<endl;
    return 0;
}
