#include <bits/stdc++.h>
using namespace std;

int dp[10001][5001];

long long int minPilotCost(int *capt,int *asst,int n,int x)
{
    if(dp[n][x] != -1)
    {
        return dp[n][x];
    }

    if(n <= 0)
    {
        return 0;
    }
    if(x == 0)
    {
        // cout<<"\nASST: "<<asst[0];
        dp[n][x] = asst[0] + minPilotCost(capt+1,asst+1,n-1,x+1);
    }
    else if(x == n)
    {
        // cout<<"\nCAPT: "<<capt[0];

        dp[n][x] = capt[0] + minPilotCost(capt+1,asst+1,n-1,x-1);
    }
    else
    {
        long long int cost1 = asst[0] + minPilotCost(capt+1,asst+1,n-1,x+1);
        long long int cost2 = capt[0] + minPilotCost(capt+1,asst+1,n-1,x-1);

        dp[n][x] = min(cost1,cost2);
    }
  	return dp[n][x];

}

int main()
{
    int n;
    cin >> n;

    int *capt = new int[n];
    int *asst = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> capt[i] >> asst[i];
    }


    for(int i = 0; i <= n; i++)
    {
        //Be cautious about the limits
        for(int j = 0; j <= n/2; j++)
            dp[i][j] = -1;
    }

    long long int minCost = minPilotCost(capt,asst,n,0);

    cout<<minCost<<endl;

    return 0;
}
