#include <bits/stdc++.h>

using namespace std;

int cost_merge(char a,char b)
{
    int cost = (a-'97'-1)^(b-'97'-1);
    return cost;
}

int lcs( string X,string Y)
{
    int m = X.size(),n = Y.size();
    int L[m+1][n+1];
    int i, j;
  
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
        
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
        
            else
            {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

int minCost(string x, string y, int k) {
    // Complete this function
    if(lcs(x,y) >= k)
        return 0;

    else
    {
        int reqd_changes = k - lcs(x,y);
        
    }
}

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    string x;
    cin >> x;
    string y;
    cin >> y;
    int result = minCost(x, y, k);
    cout << result << endl;
    return 0;
}
