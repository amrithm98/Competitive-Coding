#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxVal(int a,int b)
{
    if(a>b)
        return a;
    else    
        return b;
}
int unboundedKnapsack(vector<int> weights,int k)
{
    int n=weights.size();
    vector<int> dp(k+1);

    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(weights[j]<=i)
            {
                dp[i]=maxVal(dp[i],dp[i-weights[j]]+weights[j]);
                // cout<<"\nDP["<<i<<"]: "<<dp[i];
            }
        }
    }
    return dp[k];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    for(int t0=0;t0<t;t0++)
    {
        int n,k;
        cin>>n>>k;
        vector<int> weights(n);
        int i,j;
        for(i=0;i<n;i++)
            cin>>weights[i];
        cout<<unboundedKnapsack(weights,k)<<endl;
    }  
    return 0;
}
