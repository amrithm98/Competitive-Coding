#include <bits/stdc++.h>
using namespace std;

int coinChange(int denominations[], int numDenominations, int value,int **dp)
{
    if(numDenominations == 0)
    {
        return 0;
    }

    if(value == 0 )
    {
        return 1;
    }

    if(value < 0)
    {
        return 0;
    }
    
    if(dp[value][numDenominations] > -1)
    {
        return dp[value][numDenominations];
    }
    
    int ans1 = coinChange(denominations,numDenominations,value-denominations[0],dp);
    int ans2 = coinChange(denominations+1,numDenominations-1,value,dp);
    dp[value][numDenominations] = ans1+ans2;
    return ans1+ans2;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **dp = new int*[value+1];
    for(int i = 0; i <= value; i++)
    {
        dp[i] = new int[numDenominations+1]; 
        for(int j = 0; j <= numDenominations; j++) 
            dp[i][j] = -1;
    }
    return coinChange(denominations,numDenominations,value,dp);
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int val;
    cin >> val;

    cout << countWaysToMakeChange(arr,n,val);

    return 0;
}