#include <bits/stdc++.h>
using namespace std;

void knapsack_optim(int *fee,int *fun,int n,int budget)
{
    int *dp[2];
    dp[0] = new int[budget+1];
    dp[1] = new int[budget+1];

    for(int i = 0; i <= budget ; i++)
    {
        dp[0][i] = 0;
    }   

    dp[1][0] = 0;
    bool k = 1;
    int w;

    for(int i = 1; i <= n ; i++ , k=!k)
    {
        w = 0;
        while(w < fee[i-1] && w <= budget)
        {
            dp[k][w] = dp[!k][w];
            w++;
        }
        while(w <= budget){
            dp[k][w] = max(dp[!k][w],fun[i-1] + dp[!k][w-fee[i-1]]);
            w++;
        }
    }
    int exhausted_bud = 0;
    int ans = dp[!k][budget];

    for(int i = 0; i <= budget; i++)
    {
        if(dp[!k][i] == ans)
        {
            exhausted_bud = i;
            break;
        }
    }
    
    if(exhausted_bud == 0)
        exhausted_bud = 1;
        
    cout<<exhausted_bud<<" "<<ans<<endl;
    
    delete [] dp[0];
    delete [] dp[1];

}

int main()
{
    int budget,n;
    cin >> budget >> n;

    while(budget != 0 && n != 0)
    {
        int *fee = new int[n];
        int *fun = new int[n];

        for(int i = 0 ; i < n; i++)
        {
            cin >> fee[i] >> fun[i];
        }

        knapsack_optim(fee,fun,n,budget);

        cin >> budget >> n;
    }

    return 0;
}
