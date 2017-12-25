#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long dp[101][101][2];

long long adjacentBitCounts(int n,int k,int first)
{
    if(dp[n][k][first] >= 0)
        return dp[n][k][first];

    if(n == 1)
    {
        if(k == 0)
        {
            dp[n][k][first] = 1;
            return 1;
        }
        else
        {
            dp[n][k][first] = 0;
            return 0;
        }
    }

    if(k < 0)   
    {
        dp[n][k][first] = 0;
        return 0;
    }

    if(first == 1)
    {
        long long ans1 = adjacentBitCounts(n-1,k-1,1);
        long long ans2 = adjacentBitCounts(n-1,k,0);
        dp[n][k][first] = (ans1 + ans2)%MOD;
    }
    else
    {
        long long ans1 = adjacentBitCounts(n-1,k,1);
        long long ans2 = adjacentBitCounts(n-1,k,0);
        dp[n][k][first] = (ans1 + ans2)%MOD;
    }
    
    return dp[n][k][first];
}

long long countBits(int n,int k)
{
    long long ans = (adjacentBitCounts(n,k,0)+adjacentBitCounts(n,k,1))%MOD;
    return ans;
}

int main()
{
    int t;
    cin >> t;

    for(int i = 0; i <= 101; i++)
    {
        for(int j = 0; j <= 101; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }

    while(t--)
    {
        int a,n,k;
        cin >> a >> n >> k ;
        cout<<a<<" "<<countBits(n,k)<<endl;
    }
    return 0;

}