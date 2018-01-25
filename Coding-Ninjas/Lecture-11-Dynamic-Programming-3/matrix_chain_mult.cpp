#include <bits/stdc++.h>
using namespace std;

int matrixMultiply(int *p,int **dp,int i,int j)
{
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int minCost = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int ans = matrixMultiply(p,dp,i,k) + matrixMultiply(p,dp,k+1,j) + p[i-1]*p[k]*p[j];
        minCost = min(minCost,ans);
    }
    dp[i][j] = minCost;
    return dp[i][j];
}

int mcm(int *p,int n)
{
    int **dp = new int*[n];
    for(int i = 0; i < n; i++)
    {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    return matrixMultiply(p,dp,1,n-1);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n+1];
    for(int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << mcm(arr,n+1);
    return 0;
}