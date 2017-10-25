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
    // for(i = 2; i <= n ; i++)
    //         cout<<sieve[i]<<" ";
    return sieve;
}

int main()
{
    int n;
    cin >> n;
    vector<int> lpd = sieve_lpd(n);
    int i,j;

    vector<bool> marked(n+1);
    for(i = 0; i <=n ; i++)
        marked[i] = false;
    
    for(i = n; i>=1; i--)
    {
        if(!marked[i])
        {
            vector<int> gcdVals;
            gcdVals.push_back(i);
            marked[i] = true;
            int x = i;
            while(x!=1)
            {
                for(j = i - lpd[x]; j>= 1; j -= lpd[x])
                {
                    if(!marked[j])
                    {
                        gcdVals.push_back(j);
                        marked[j] = true;
                    }
                }
                int lpd_x = lpd[x];
                while( x%lpd_x == 0 )
                {
                    x /= lpd_x;
                }
            }
            
            sort(gcdVals.begin(),gcdVals.end(),greater<int>());
            for(int k = 0; k <gcdVals.size(); k++)
                cout<<gcdVals[k]<<" ";
        }
    }
}