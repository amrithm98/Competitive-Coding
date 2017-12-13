#include <bits/stdc++.h>
using namespace std;


int maxBlessingHelper(string s1,string s2,int m,int n,int ***dp,int k)
{
    int option1 = -1;

    if(k == 0)
    {
        return 0;
    }

    if(m == -1 || n == -1 )
    {
        return -1;
    }

    if(dp[m][n][k] != -2)
        return dp[m][n][k];

    if(s1[m] == s2[n])
    {
        option1 = maxBlessingHelper(s1,s2,m-1,n-1,dp,k-1);
        if(option1 != -1)
            option1 += s1[m];
    }

    int option2 = -1;
    int option3 = -1;

    option2 = maxBlessingHelper(s1,s2,m-1,n,dp,k);
    option3 = maxBlessingHelper(s1,s2,m,n-1,dp,k);
    dp[m][n][k] = max(option1,max(option2,option3));
    return dp[m][n][k];
}

int maxBlessing(string s1,string s2,int k)
{
    int m = s1.size();
    int n = s2.size();

    if( m < k || n < k )
        return 0;

    int ***dp = new int**[m+1];
    for(int i = 0; i <= m ; i++)
    {
        dp[i] = new int*[n+1];
        for(int j = 0; j <= n ; j++)
        {
            dp[i][j] = new int[k+1];
            for(int l = 0; l <= k ; l++)
                dp[i][j][l] = -2;
        }
    }

    int ans = maxBlessingHelper(s1,s2,m-1,n-1,dp,k);
    if(ans == -1)
        ans = 0;
        
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n ; j++)
            delete [] dp[i][j];

    delete [] dp;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int k;
        cin >> k;
        cout<<maxBlessing(s1,s2,k)<<endl;
    }
    return 0;
}
