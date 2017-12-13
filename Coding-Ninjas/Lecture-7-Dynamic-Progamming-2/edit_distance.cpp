#include <bits/stdc++.h>
using namespace std;

int editDistance_naive(string s1,string s2,int m,int n)
{

    if(m == 0)
    {
        return n;
    }

    if(n == 0)
    {
        return m;
    }

    if(s1[m-1] == s2[n-1])
    {
        return editDistance_naive(s1,s2,m-1,n-1);
    }

    else
    {
        int insert = editDistance_naive(s1,s2,m,n-1);
        int del = editDistance_naive(s1,s2,m-1,n);
        int replace = editDistance_naive(s1,s2,m-1,n-1);
        int ans = 1 + min(insert,min(del,replace));
        return ans;
    }

}

int minDistHelper(string s1,string s2,int m,int n,int **dp)
{

    if(dp[m][n] > -1)
        return dp[m][n];

    if(s1[m-1] == s2[n-1])
    {
        dp[m][n] = minDistHelper(s1,s2,m-1,n-1,dp);
        return dp[m][n];
    }

    else
    {
        int insert = minDistHelper(s1,s2,m,n-1,dp);

        int del = minDistHelper(s1,s2,m-1,n,dp);

        int replace = minDistHelper(s1,s2,m-1,n-1,dp);

        int ans = 1 + min(insert,min(del,replace));
        dp[m][n] = ans;

        return ans;
    }
}

int editDistance_optim(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **dp = new int*[m+1];
    
    for(int i = 0; i <= m ; i++)
    {
        dp[i] = new int[n+1];
        for(int j = 0; j <= n ; j++)
            dp[i][j] = -1;
    }

    dp[0][0] = 0;

    for(int i = 1; i <= m ; i++)
        dp[i][0] = i;

    for(int i = 1; i <= n ; i++)
        dp[0][i] = i;
    
   
    int ans = minDistHelper(s1,s2,m,n,dp);
    ans = dp[m][n];

    // for(int i = 0; i <= m; i++)
    // {
    //     for(int j = 0; j <= n; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    for(int i = 0; i <= m; i++)
        delete [] dp[i];
    delete [] dp;

    return ans;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    cout << editDistance_optim(s1,s2) << endl;
    cout << editDistance_naive(s1,s2,s1.size(),s2.size()) << endl;

    return 0;
}