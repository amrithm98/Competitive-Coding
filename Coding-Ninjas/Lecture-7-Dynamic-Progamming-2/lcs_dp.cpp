#include<bits/stdc++.h>
using namespace std;

int lcs(char *c1,char *c2)
{
    if(c1[0] == '\0' || c2[0] == '\0')
    {
        return 0;
    }
    if(c1[0] == c2[0])
    {
        return 1 + lcs(c1+1,c2+1);
    }
    else
    {
        int opt1 = lcs(c1+1,c2);
        int opt2 = lcs(c1,c2+1);
        return max(opt1,opt2);
    }
}

int lcs_helper(char *c1,char *c2,int m,int n, int **dp)
{
    if(m == 0 || n == 0)
    {
        return 0;
    }

    if(dp[m][n] > -1)
    {
        return dp[m][n];
    }

    int ans;

    if(c1[0] == c2[0])
    {
         ans = 1 + lcs_helper(c1+1,c2+1,m-1,n-1,dp);

    }
    else
    {
        int opt1 = lcs_helper(c1+1,c2,m-1,n,dp);
        int opt2 = lcs_helper(c1,c2+1,m,n-1,dp);
        ans =  max(opt1,opt2);
    }
    dp[m][n] = ans;
    return ans;
}

int lcs_dp(char *c1,char *c2)
{
    int m = strlen(c1);
    int n = strlen(c2);
    int **dp = new int*[m+1];
    for(int i = 0; i <= m ; i++)
    {
        dp[i] = new int[n+1];
        for(int j = 0; j <= n ; j++)
            dp[i][j] = -1;
    }

    int ans = lcs_helper(c1,c2,m,n,dp);

    for(int i = 0; i <= m ; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    
    return ans;
}

int main()
{
    char c1[100],c2[100];
    cin >> c1 >> c2;
    cout<<lcs_dp(c1,c2)<<endl;
    return 0;
}
