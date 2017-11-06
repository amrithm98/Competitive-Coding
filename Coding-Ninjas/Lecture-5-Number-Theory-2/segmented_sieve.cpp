#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
vector<int> sieve()
{
    bool isPrime[MAX];
    int i;
    for(i = 0; i < MAX ; i++)
        isPrime[i] = true;
    
    for(i = 2 ; i*i < MAX ; i++)
    {
        for(int j = i*i ; j <MAX ; j += i)
        {
            isPrime[j] = false;
        }
    }

    vector<int> primes;
    primes.push_back(2);

    for(i = 3; i < MAX ; i++)
        if(isPrime[i])
            primes.push_back(i);

    return primes;
}

void printPrimes(long long l,long long r,vector<int> primes)
{
    bool isPrime[r-l+1];
    for(int i = 0; i <= r-l ; i++)
        isPrime[i] = true;

    for(int i = 0; (long long)primes[i]*primes[i] <= r; i++)
    {
        int currPrime = primes[i];
        long long base = (l/currPrime)*currPrime;
        if(base<l)
            base += currPrime;

        for(long long j = base; j <= r; j+= currPrime)
        {
            isPrime[j-l] = false; 
        }

        if(base == currPrime)
            isPrime[base - l] = true;  
    }   

    for(int i = 0; i <= r-l ; i++)
    {
        if(isPrime[i] == true)
            cout<<i+l<<endl;
    }
}

int main()
{
     int t;
     cin >> t;
     vector<int> primes = sieve();
    //  for(auto i : primes)
    //     cout<<i<<" ";

     while(t--)
     {
         long long l,r;
         cin >> l >> r;
         printPrimes(l,r,primes);
     }
     return 0;
}