#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define mod 1000000007
#define MAX 1000000
using namespace std;

int countGoodSets(vector<int> sieve,int size)
{
    for(int i = 0; i < size; i++)
    {
        if(sieve[i])
        {
            for(int j = i*2; j <= size-1; j+=i)
            {
                if(sieve[j])
                    sieve[j] = (sieve[i]%mod + sieve[j]%mod)%mod;
            }
        }
    }
    int sum = 0;
    for(int i =0; i<size; i++)
        sum = (sum%mod+sieve[i]%mod)%mod;
    return sum;
}

int main()
{
	// Write your code here
    int t;
    cin >> t;
    while(t--)
    {
        long n,i,j;
        cin >> n;

        vector<long> arr(n);
        int max = INT8_MIN;
        for( i = 0 ; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] > max)
                max = arr[i];
        }
        vector<int> sieve(max+1);

        for(int i = 0;i<n;i++)
        {
            sieve[arr[i]] = 1;
        }
                
        cout<< countGoodSets(sieve,max+1) << endl;
    }
	return 0;
}