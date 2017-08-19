#include <bits/stdc++.h>

using namespace std;

int traderProfit(int k, int n, vector <int> A) {
   int profit[k+1][n+1];
   int i,j;
   for(i=0;i<=k;i++)
   {
       profit[i][0]=0;
   }
   for(j=0;j<=n;j++)
   {
       profit[0][j]=0;
   }
   for(i=1;i<=k;i++)
   {
       for(j=1;j<n;j++)
       {
            int max_val=INT8_MIN;
            for(int l=0;l<j;l++)
            {
                max_val=max(max_val,A[j]-A[l]+profit[i-1][l]);
            }
            profit[i][j]=max(profit[i][j-1],max_val);
       }
   }
   return profit[k][n-1];
}
int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
    }
    return 0;
}
