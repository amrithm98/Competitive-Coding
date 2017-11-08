#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001

long long *G = new long long[MAX];
int *sieve = new int[MAX];

void etf_sieve()
{
    for(int i = 1; i < MAX ; i++)
    {
        sieve[i] = i;
        G[i] = 0;
    }
    
    for(int i = 2; i < MAX ; i++)
    {
        if(sieve[i] == i)
        {
            sieve[i] = sieve[i] -1;
            for(int j = 2*i; j < MAX ; j += i)
            {
                sieve[j] -= (sieve[j]/i);
            }
        }
    }

    //Testing Sieve
    // for(int i = 0; i < 10 ; i++)    
    //     cout<<sieve[i] <<endl;
    
    for(int i = 1 ; i<MAX ; i++)
    {
        for(int j = 2 ; i*j < MAX ; j++ )
        {
            G[i*j] += i*sieve[j];
        }
    }
  
  for (int i=2; i<MAX; i++)
        G[i] += G[i-1];

}
int main() {

	// Write your code here
    etf_sieve();
    int n;
    cin >> n;
    while(n != 0)
    {
        cout<<G[n]<<endl;
        cin>>n;
    }
    return 0;
}