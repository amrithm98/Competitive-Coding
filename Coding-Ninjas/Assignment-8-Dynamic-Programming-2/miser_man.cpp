#include <bits/stdc++.h>
using namespace std;

int input[101][101];
int dp[102][102];

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> input[i][j];

    for(int i = 0; i <= n+1; i++)
    {
        input[i][m+1] = INT8_MAX;
        input[i][0] = INT8_MAX;
    }

    for(int i = 1; i <= n+1; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i-1][j+1] + input[i-1][j+1] , min(dp[i-1][j] + input[i-1][j],dp[i-1][j-1] + input[i-1][j-1]) );
        }
    }
    int min_cost = INT8_MAX;

    for(int i = 1; i <= m; i++)
    {
        if(dp[n+1][i] < min_cost)
            min_cost = dp[n+1][i];
    }

    cout<<min_cost<<endl;

    return 0;
}
