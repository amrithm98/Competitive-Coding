#include <iostream>
#include <cmath>
#define mod 1000000007

using namespace std;

long long sumOfNaturalNos(long long n,long long start = 0)
{   
    if(n == start)
    {
        return n%mod;
    }

    long long result = 0;
    result = ((n % mod) * ((n+1)%mod)/2)%mod;
    if(start)
    {
        result = (result - (((start - 1) % mod) * (start % mod) /2) + mod)%mod;
    }
    return result;
}
int main()
{

    long long n,i;
    cin >> n;

    long long res = sumOfNaturalNos(n);
    long long j = n,ni;

    for(i = 2; i*i <= n ; i++)
    {
        ni = n/i;
        res = (res + ((i % mod) * sumOfNaturalNos(ni))%mod)%mod;
        res = (res + (sumOfNaturalNos(i-1) * sumOfNaturalNos(j,ni+1))%mod)%mod;
        j = ni;
    }
    if(j != i-1 && n !=0)
    {
        res = (res + (sumOfNaturalNos(i-1) * sumOfNaturalNos(j,i))%mod)%mod;
    }
    cout<<res<<endl;
    return 0;
}