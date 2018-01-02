#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q,c;
    cin >> n >> q >> c;

    int dp[11][101][101];
    
    for(int i = 0 ; i < 11; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            for(int k = 0; k < 101; k++)
                dp[i][j][k] = 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        int x,y,s;
        cin >> x >> y >> s;
        dp[s][x][y]++;
    }

    for(int i = 0 ; i <= c; i++)
    {
        for(int j = 1; j < 101; j++)
        {
            for(int k = 1; k < 101; k++)
            {
                dp[i][j][k] += dp[i][j-1][k] + dp[i][j][k-1] - dp[i][j-1][k-1];
            }
        }
    }

    for(int i = 0; i < q; i++)
    {
        int ti,x1,y1,x2,y2;
        cin >> ti >> x1 >> y1 >> x2 >> y2;

        int ans = 0;
        for(int j = 0; j <= c; j++)
        {   
            int bright = (j+ti)%(c+1);
            ans = ans + ((dp[j][x2][y2] - dp[j][x1-1][y2] - dp[j][x2][y1-1] + dp[j][x1-1][y1-1])*bright);
        }
        cout<<ans<<endl;
    }       
}