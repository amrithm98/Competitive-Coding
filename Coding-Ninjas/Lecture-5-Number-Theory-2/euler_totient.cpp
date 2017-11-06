#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> etf_sieve(int n)
{
    vector<int> sieve(n+1);
    int i = 2;
    for(i = 2; i <= n ; i++)
    {
        sieve[i] = i;
    }
    for(i = 2; i <= n ; i++)
    {
        if(sieve[i] == i)
        {
            sieve[i] = sieve[i] -1;
            for(int j = 2*i; j <= n ; j += i)
            {
                sieve[j] = sieve[j]*(i-1)/i;
            }
        }
    }
    return sieve;
}

int main()
{
    int n;
    cout<<"\nEnter N: ";
    cin >> n; 
    vector<int> sieve = etf_sieve(n);
    for(int i = 2; i <= n ; i++)
        cout<< i<<" "<<sieve[i]<<endl;

}