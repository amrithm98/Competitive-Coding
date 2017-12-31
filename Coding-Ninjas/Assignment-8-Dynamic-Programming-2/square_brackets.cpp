#include <bits/stdc++.h>
using namespace std;

bool openings[40];
int dp[40][40];

int possibleBrackets(int open,int close,int n)
{
    if(openings[0])
    {
        return 0;
    }

    if(dp[open][close] != -1)
    {
        return dp[open][close];
    }

    if(open > n || close > n)
    {
        return 0;
    }

    if(open == n && close == n)
    {
        dp[open][close] = 1;
        return 1;
    }
    
    int currIndex = (open+close+1);

    if(open == close || openings[currIndex])
    {
        dp[open][close] = possibleBrackets(open+1,close,n);
    }
    else if(open == n)
    {
        dp[open][close] = possibleBrackets(open,close+1,n);
    }
    else
    {
        dp[open][close] = possibleBrackets(open+1,close,n) + possibleBrackets(open,close+1,n);
    }
    return dp[open][close];
}

int main()
{
    int d;
    cin >> d;

    while(d--)
    {
        int n,k;
        cin >> n >> k;
        memset(openings,0,sizeof(openings));
        memset(dp,-1,sizeof(dp));

        for(int i = 0; i < k ; i++)
        {
            int m;
            cin >> m;
            openings[m] = true;
        }
        cout<<possibleBrackets(0,0,n)<<endl;
    }

    return 0;
}