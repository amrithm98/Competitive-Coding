#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int distinctSubs(string str)
{
    int *dp = new int[100000];
    int *last = new int[26];

    for(int i = 0; i < 26; i++)
        last[i] = -1;
    
    dp[0] = 1;
    
    int n = str.size();

    for(int i = 1; i <= n; i++)
    {
        dp[i] = (2*dp[i-1])%MOD;

        if(last[str[i-1]-'A'] != -1)
        {
            dp[i] = (dp[i] - dp[last[str[i-1]-'A']] + MOD)%MOD;
        }
        
        last[str[i-1]-'A'] = i-1;
    }

    // for(int i = 0; i <= n; i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;

    return dp[n];
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        cout<<distinctSubs(s)<<endl;
    }

    return 0;
}
