#include <bits/stdc++.h>
using namespace std;

vector< vector<long long> > dp(2005 , vector<long long>(2005 , -1));

long long countWays(int currP,int currQ,int P,int Q,int C,set<pair<int,int>> &deedSet)
{
    if(dp[currP][currQ] != -1)
        return dp[currP][currQ];

    if(currP + currQ == P + Q)
    {
        dp[currP][currQ] = 1;
    }
    else
    {
        dp[currP][currQ] = 0;

        if(currP < P && deedSet.find({currP+1,currQ}) == deedSet.end())
            dp[currP][currQ] = countWays(currP+1,currQ,P,Q,C,deedSet);

        if(currQ < Q && (currP - currQ) > C && deedSet.find({currP,currQ+1}) == deedSet.end())
            dp[currP][currQ] = (dp[currP][currQ] + countWays(currP,currQ+1,P,Q,C,deedSet))%1000000007;
    }
    
    return dp[currP][currQ];
}

int main()
{
    int p,q,c,M;
    cin >> p >> q >> c >> M;

    vector<pair<int,int>> deed(M);
    for(int i = 0; i < M; i++)
        cin >> deed[i].first >> deed[i].second;

    set<pair<int,int>> deedSet;
    for(auto it : deed)
    {   
        if(it.first > p || it.second > q)
            continue;
        else
            deedSet.insert(make_pair(it.first,it.second));
    }

    if(p-c < q)
    {
        cout << 0 << endl;
    }
    else
        cout << countWays(0,0,p,q,c,deedSet) << endl;

    return 0;
}