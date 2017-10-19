#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	// Write your code here
    int n;
    cin >> n;

    vector<bool> sieve(n+1);

    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2;i <= n;i++)
        sieve[i] = true;

    for(int i = 2; i <= sqrt(n); i++)
    {
        if(sieve[i])
            for(int j = i*i ; j <= n ; j+=i)
            {
                sieve[j] = false;
            }
    }
    
    int count = 0;
    for(int i = 0; i <= n; i++)
        if(sieve[i])    
            count++;
    cout<<count<<endl;
	return 0;
}