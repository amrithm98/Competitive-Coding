#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
long long int dp[2][MAX];

int main()
{
    long long int n,m,k;
    cin >> n >> m;

    long long int **arr = new long long int*[n];
    for(long long int i = 0; i < n; i++)
        arr[i] = new long long int[m];
    
    for(long long int i = 0; i < n; i++)
        for(long long int j = 0; j < m; j++)
            cin >> arr[i][j];

    cin >> k;

    long long int *min_cols = new long long int[n];

    for(long long int i = 0; i < m; i++)
        dp[0][i] = 0;
    
    long long int flag = 1;
    for(long long int i = 1; i < n; i++)
    {
        long long int min_ind = 1000000007;
        for(long long int j = 0; j < m; j++)
        {
            if(arr[i][j] >= arr[i-1][j])
            {
                dp[flag][j] = dp[flag^1][j];
            }
            else
            {
                dp[flag][j] = i;
            }

            if(dp[flag][j] < min_ind)
                min_ind = dp[flag][j];
        }
        flag = flag^1;
        min_cols[i] = min_ind;
    }

    for(long long int i = 0; i < k ; i++)
    {
        long long int l,r;
        cin >> l >> r;
        l--,r--;
        if(min_cols[r] <= l)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<endl;
    }
    return 0;
}
