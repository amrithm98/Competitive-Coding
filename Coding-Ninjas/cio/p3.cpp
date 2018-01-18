#include<bits/stdc++.h>
using namespace std;
int dp[501][501];

int sol(int a,int left,int k)
{

    if(left == 0)
    {
        return 1;
    }

    if(a == k || a > left)
    {
        return 0;
    }

    if(left < 0)
    {
        return 0;
    }

    return sol(a+1,left-a,k) + sol(a+1,left,k);
}
int main()
{
    int x;
    cin >> x;
    for(int i = 0; i < 501;i++)
        dp[i] = -1;

    sol(1,x,x);
    for(int i = 0; i <= x;i++)
        cout<<dp[i]<<" ";
    return 0;
}