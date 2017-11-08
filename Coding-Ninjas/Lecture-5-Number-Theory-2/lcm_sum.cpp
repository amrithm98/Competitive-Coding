#include<bits/stdc++.h>
using namespace std;

void func(long long n)
{
	// Write your code here
    long long etf_sieve[n+1];
    long long i,j;
    for(i = 1; i <= n; i++)
        etf_sieve[i] = i;

    for(i = 2; i <= n ; i++)
    {
        if(etf_sieve[i] == i)
        {
            etf_sieve[i] -= 1;
            for(j = 2*i; j <= n ; j += i)
            {
                etf_sieve[j] = (etf_sieve[j]*(i-1))/i;
            }
        }
    }
    long long result = 0;
    for(i = 1; i <= n ; i++)
    {
        if(n%i == 0)
        {
            result += (etf_sieve[i]*i);
        }
    }

    result = (result+1)*n/2;
    cout<<result;
}

int main()
{
    long long n;
    cin >> n;
    func(n);
}