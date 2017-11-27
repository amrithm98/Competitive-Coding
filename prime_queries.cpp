#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define MAX 1000001
vector<bool> sieve_of_eratosthenes()
{
    vector<bool> sieve(MAX);

    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2;i <= MAX;i++)
        sieve[i] = true;

    for(int i = 2; i <= sqrt(MAX); i++)
    {
        if(sieve[i])
            for(int j = i*i ; j <= MAX ; j+=i)
            {
                sieve[j] = false;
            }
    }

    return sieve;
}
int main()
{
	// Write your code here
    
    int t;
    cin >> t;
    vector<bool> sieve = sieve_of_eratosthenes();
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        int temp_a = a,temp_b = b;
        if(sieve[a] == false)
        {
            while(sieve[a] != true && a <= temp_b)
                a++;
            
            if(a>temp_b)
            {
                cout<<0<<endl;
                continue;
            }
        }
        if(sieve[b] == false)
        {
            while(sieve[b] != true && b >= temp_a)
                b--;
            if(b<temp_a)
            {
                cout<<0<<endl;
                continue;
            }
        }
        // cout<<a<<" "<<b<<endl;
        cout<<abs(a-b)<<endl;
    }
    
}