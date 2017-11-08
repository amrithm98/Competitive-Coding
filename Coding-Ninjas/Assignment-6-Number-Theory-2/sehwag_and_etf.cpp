#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define LL long long  

vector<int> primes;

void prime()
{
    bool *sieve = new bool[MAX+1];

    for(int i = 2; i <= MAX ; i++)
        sieve[i] = true;

    for(int i = 2; i*i <= MAX ; i++)
    {
        for(int j = i*i ; j <= MAX; j += i)
        {
            sieve[j] = false;
        }
    }
    primes.push_back(2);
    for(int i = 3 ; i <= MAX ; i++)
        if(sieve[i])
            primes.push_back(i);
}

LL findDivisibleETF(LL l,LL r,LL k)
{
    vector<pair<LL,LL>> segmentedSieve(r-l+1);
    for(int i = 0; i <= r-l; i++)
        segmentedSieve[i] = make_pair(l+i,l+i);
    
    for(int i = 0; i < primes.size(); i++)
    {
        int currPrime = primes[i];
        LL base = (l/currPrime)*(long long)currPrime;

        if(base<l)
            base += currPrime;
        
        /**
         * Extending ETF (Segmented) But We only have factors till root(n)
         * We Store two values... 1 st one the ETF and second one the factor on dividing the number with all prime divisors
         * If the 2nd values is not 1..then it means it's a prime number
         * Let that prime number be segmentedSieve[i].second
         * We have to multiply (i-1)/i for segmentedSieve[i].first to get the correct totient
         * **/

        for(LL j = base; j <= r; j += currPrime)
        {
            segmentedSieve[j-l].first -= (segmentedSieve[j-l].first/currPrime);
            while(segmentedSieve[j-l].second % currPrime == 0)
            {
                segmentedSieve[j-l].second /= currPrime;
            }
        }
    }

    LL count = 0;
    for(int i = 0; i <= r-l ; i++)
    {
        if(segmentedSieve[i].first == i+l && i+l != 1)
            segmentedSieve[i].first --;

        else if(segmentedSieve[i].second > 1)
            segmentedSieve[i].first -= segmentedSieve[i].first/segmentedSieve[i].second;

        // cout<<segmentedSieve[i].first<<" : "<<segmentedSieve[i].second<<endl;
        if(segmentedSieve[i].first % k == 0)
            count ++;
    }
    return count;
}


int main() 
{

	// Write your code here
    prime();
    int t;
    cin >> t;
    while(t--)
    {
        LL l,r,k;
        cin >> l >> r >> k;
        LL count_div_k = 0;
        count_div_k = findDivisibleETF(l,r,k);
        // cout<<count_div_k<<endl;
        long double ans = count_div_k/(long double)(r-l+1);
        cout << setprecision(6) << fixed << ans<< endl;
    }
    return 0;
}