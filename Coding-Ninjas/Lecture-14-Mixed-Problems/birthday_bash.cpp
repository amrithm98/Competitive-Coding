#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long int
#define MOD 1000000007

LL ans = 0;

LL dfs(int start,int parent,unordered_map<int,LL> *edges)
{
    LL curr = 1;

    for(auto it : edges[start])
    {
        pair<int,LL> edge = it;
        if(edge.first != parent)
        {
            LL child = dfs(edge.first,start,edges);
            ans += (((child*edge.second)%MOD)*(curr%MOD))%MOD;
            curr += (child*edge.second);
            if(curr >= MOD)
                curr = curr % MOD;
            if(ans >= MOD)
                ans = ans % MOD;
        }
    }

    return curr;
}

int main()
{
    //Write your code here
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;


    unordered_map<int,LL> *edges = new unordered_map<int,LL>[n+1];

    for(int i = 1; i < n; i++)
    {
        int a,b;
        LL c;
        cin >> a >> b >> c;
        edges[a][b] = c;
        edges[b][a] = c;
    }

    dfs(1,-1,edges);
    cout << ans << endl;
    
    return 0;
}