#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define mod 1000000007 
#define MAX 50001
vector<int> sieve_of_eratosthenes()
{
    vector<int> sieve(MAX);

    sieve[0] = false;
    sieve[1] = false;

    for(int i =2 ;i <= MAX;i++)   
        sieve[i] = true;

    for(int i = 2; i <= sqrt(MAX);i++)
    {
        if(sieve[i])
            for(int j = i*i; j <=MAX ;j += i)
                sieve[j] = false;
    }

    vector<int> primes;
    primes.push_back(2);
    for(int i = 3; i<= MAX; i++)
        if(sieve[i])
            primes.push_back(i);

    return primes;

}


long long divisorOfFactorial(vector<int> sieve,int n)
{
    long long divisors = 1;
    for(int i = 0; sieve[i] <= n; i++)
    {
       long long count = 0;
       int k = sieve[i];
       while(n/k != 0)
       {
            count = (count%mod + (n/k)%mod)%mod;
            k = k*sieve[i];
       }
       count = (count + 1)%mod;
       divisors = (divisors * count)%mod;
    }

    return divisors;
}

int main(){
	// Write your code here
    vector<int> sieve;
    sieve = sieve_of_eratosthenes();

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        cout<<divisorOfFactorial(sieve,n)<<endl;
    }
	return 0;
}