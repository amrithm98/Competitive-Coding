#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x;
    cin >> n >> k >> x;

    int **dp = new int*[2];
    for(int i = 0; i < 2; i++)
        dp[i] = new int[1024];
    
    for(int i = 0;i < n; i++)
    {
        int v;
        cin >> v;
        dp[0][v]++;
    }

    int traversed_count;
    int flag = 0;

    for(int i = 0; i < k; i++)
    {
        traversed_count = 1;
        for(int j = 0; j <= 1023; j++)
        {
            if(dp[flag][j] != 0)
            {
                if(traversed_count % 2 == 1 && dp[flag][j] % 2 == 1)
                {
                    dp[flag^1][j^x] += dp[flag][j]/2 + 1;
                    dp[flag^1][j] += ( dp[flag][j] - (dp[flag][j]/2 + 1) );
                }
                else
                {
                    dp[flag^1][j^x] += dp[flag][j]/2;
                    dp[flag^1][j] += ( dp[flag][j] - (dp[flag][j]/2) );
                }

                traversed_count += dp[flag][j];
                dp[flag][j] = 0;
            }
        }
        flag = flag^1;
    }

    int max_val = 0;
    int min_val = 1023;

    for(int i = 0; i <= 1023; i++)
    {
        if(dp[flag][i] != 0)
        {
            if(i > max_val)
                max_val = i;
            if(i < min_val)
                min_val = i;
        }
    }

    cout<<max_val<<" "<<min_val<<endl;
    return 0;
}
