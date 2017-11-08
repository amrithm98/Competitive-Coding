#include<bits/stdc++.h>
using namespace std;

long long modRecursive(long long a,long long b,long long mod)
{
    if(b == 0)
        return 1;
    long long result = modRecursive(a,b/2,mod);
    result = (result*result)%mod;
    if(b % 2 != 0)
        result = ((a%mod)*result)%mod;
    return result;
}

int main() 
{

	// Write your code here
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        int m;
        cin >> n >> m;
        long long intervals = n/m;
        long long intervalMod = modRecursive(m-1,intervals,m);
        long long start = n-(n/m)*m;
        long long n_fact_mod_m = 1;

        for(long long i = start+1; i < m ; i++)
            n_fact_mod_m = (n_fact_mod_m*i)%m;
        
        n_fact_mod_m = modRecursive(n_fact_mod_m,m-2,m);
        n_fact_mod_m = (n_fact_mod_m * intervalMod)%m;
        n_fact_mod_m = (n_fact_mod_m * (m-1))%m;
        cout<<n_fact_mod_m<<endl;
    }
}