#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 1000001
using namespace std;

vector<long> sieve_of_eratosthenes()
{
    vector<bool> sieve(MAX);
    vector<long> divisorCount(MAX);

    sieve[0] = false;
    sieve[1] = false;

    for(long i = 2; i <= MAX ; i++)
        sieve[i] = true;

    for(long i = 2 ; i <= sqrt(MAX) ; i++)
    {
        for(long j = i*i; j <= MAX ; j+=i)
        {
            sieve[j] = false;
        }
    }

    vector<long> primes;
    primes.push_back(2);

    for(long i = 3; i <= MAX; i++)
        if(sieve[i])
            primes.push_back(i);

    for(int i = 0; i < primes.size(); i++)
    {
        for(int j = 1; primes[i]*j <= MAX ; j++ )
            divisorCount[ primes[i]*j ] ++;
    }
    // for(int i = 0; i < 15; i++)
    //     cout<<divisorCount[i]<<" ";

    return divisorCount;

}

int main()
{
	// Write your code here
    int t;
    cin >> t;

    vector<long> sieve;
    sieve = sieve_of_eratosthenes();

    while(t--)
    {
        long long a,b;
        int n;

        cin >> a >> b >>n;

        int n_factor = 0;

        for(long i = a; i <= b; i++)
        {
            if(sieve[i] == n)
                n_factor++;
        }

        cout<< n_factor << endl;
    }
	return 0;
}