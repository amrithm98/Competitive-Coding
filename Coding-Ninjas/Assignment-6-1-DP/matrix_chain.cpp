#include <bits/stdc++.h>
using namespace std;

/***
 *  M1... Mn Matrices
 *  Find Placement of brackets between Ms and Me
 *  Indices are 0 to n+1
 *  For matrix (s,e), indices will be from s-1 to e. Try placing k from s+1 to e-1
 *  Base is a single index(No Matrix) or 2 adjacent indices (1 Matrix). No Mult Needed in either case
 *  Recursively find f(p,s,k) and f(p,k,e)
 *  add p[s]*p[k]*p[e] to mult matrices (s+1,e)
 *  
 * */

int matrixChain(int *p,int start, int end,int **dp)
{
    if(start == end || start == end-1)
    {
        return 0;
    }
    
    if(dp[start][end] > -1)
    {
        return dp[start][end];
    }

    int min_ans = INT_MAX;

    for(int k = start+1; k <= end-1; k++)
    {
        int ans1 = matrixChain(p,start,k,dp);
        int ans2 = matrixChain(p,k,end,dp);
        int reqMul = p[start]*p[k]*p[end];

        min_ans = min(min_ans,ans1+ans2+reqMul);
    }

    dp[start][end] = min_ans;

    return min_ans;
}

int mcm(int* p, int n)
{
    int **dp = new int*[n+1];

    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[n+1];
        for(int j = 0; j <= n; j++)
            dp[i][j] = -1;
    }

    matrixChain(p,0,n,dp);
    return dp[0][n];
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n+1];
    for(int i = 0; i <= n; i++)
        cin >> arr[i];

    cout << mcm(arr,n) << endl;
    return 0;

}
