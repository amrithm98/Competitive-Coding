#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    long long blocks[105];
    long long sum[105],best[105];
    long long dp[105][2005];


    for(int i = 1; i <= n; i++)
    {
        int size;
        cin >> size;
        // cout<<"\nFIRST ROW "<<size;
		blocks[1] = size;
        size++;
        
        for(int j = 2; j <= size; j++)
        {
            cin >> blocks[j];
        }

        sum[0] = 0;

        for(int j = 1; j <= size ; j++)
        {
            sum[j] = sum[j-1] + blocks[j];
        }

        for(int j = 1; j <= m; j++)
        {   
            best[j] = -1000000001;
        }

        best[0] = 0;

        for(int j = 1; j <= size; j++)
        {
            for(int q = 1; q <= m && q+j-1 <= size; q++)
            {
                best[q] = max(best[q],sum[j+q-1]-sum[j-1]);
            }
        }

        for(int j = 0; j <= m; j++)
        {
            for(int k = 0; k <= m; k++)
            {
                dp[i][j+k] = max(dp[i][j+k],dp[i-1][j] + best[k]);
            }
        }
    }
  
    long long int max = -1000000001;
    for(int i = 0; i <= m; i++)
    {
        if(dp[n][i] > max)
        {
            max = dp[n][i];
        }
    }
    cout<<max<<endl;
    
    return 0;
}
