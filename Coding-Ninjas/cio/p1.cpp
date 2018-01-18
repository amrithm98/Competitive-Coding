#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> sieve_lpd(int n)
{
    int i = 0,j = 0;
    vector<int> sieve(n+1);
    for(i = 2; i <= n ; i++)
        sieve[i] = i;
        
    for(i = 2; i <= sqrt(n) ; i++)
    {
        for(j = 2*i; j <= n ;j += i)
        {
            if(sieve[j] == j)
                sieve[j] = i;
        }
    }
    
    return sieve;
}

int main()
{
    int n,l;
    cin >> n >> l;
    vector<int> sieve = sieve_lpd(10000000);

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int count = 0;
        for(int j = 2; j <= l; j++)
        {
            if(sieve[j] == a)
                count++;
        }
        cout<<count<<endl;
    }
}