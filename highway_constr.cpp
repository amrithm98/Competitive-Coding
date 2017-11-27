#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009

long long int modPower(long long int a , long long int b)
{
    if(b == 0)
        return 1;
    long long int result = modPower(a,b/2);
    result = (result * result) % MOD;

    if(b%2 != 0)
        result = (result * a)%MOD;
    return result;
}

//This is Correct
void countP(int n, int k,long long int dp[][1001])
{
  for (int i=0; i<=n; i++)
    for(int j = 0; j <= k ; j++)
        dp[i][j] = 0;

  for (int i=1; i<=n; i++)
     for (int j=1; j<=i; j++)
       if (j == 1 || i == j)
          dp[i][j] = 1;
       else
          dp[i][j] = ((j*dp[i-1][j])%MOD + (dp[i-1][j-1])%MOD)%MOD;
}

//This is correct
long long int fallingFact(long long int n,int k)
{
    if(k == 0)
        return 1;
    if( k == 1)
        return n%MOD;
    long long int ans = n;
    long long int res = 1;
    long long int next;
    for(int i = 1; i < k ; i++)
    {
        res = ans%MOD;
        next = (n-i)%MOD;
        ans = (res * next)%MOD;
        // if(k<5)
        // cout<<"FAll Fact: "<<k<<" "<<res<<" "<<next<<" "<<ans<<endl;
    }
    return ans;
}

long long int highwayConstruction_Sterling(long long int n, int k) {
    // Complete this
    long long int sum = (n+1)%MOD;
    long long int stirling_mat[1001][1001];
    countP(1000,1000,stirling_mat);
    long long int res = 0;
    for(int i = 0; i <= k ; i++)
    {
        // cout<<k<<" "<<i<<" "<<stirling_mat[k][i]<<endl;
        long long int ff = fallingFact(n,i);
        long long int sm = stirling_mat[k][i];
        // long long smallProd = (ff * sm)%MOD;
        // long long smallDiv = (smallProd*modPower(i+1,MOD-2))%MOD;
        long long int modInverse = modPower(i+1,MOD-2)%MOD;
        long long int smallDiv = ((ff%MOD) * (modInverse%MOD))%MOD;
        long long int smallProd = ((sm%MOD) * (smallDiv%MOD))%MOD;
        res = (res%MOD + smallProd%MOD)%MOD;
        // if(i < 5)
        //     cout<<ff<<" "<<modInverse<<" "<<sm<<" "<<smallDiv<<" "<<smallProd<<" "<<res<<endl;
    }

    sum = ((sum%MOD) * (res%MOD))%MOD;
    sum = (sum%MOD - 1 - modPower(n,k) + MOD)%MOD;
    return sum;
}

int main() 
{
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long long int n;
        int k;
        cin >> n >> k;
        if(n <= 1)
        {
            cout<<0<<endl;
            continue;
        }
        long long int result = highwayConstruction_Sterling(n, k);
        cout << result << endl;
    }
    return 0;
}
