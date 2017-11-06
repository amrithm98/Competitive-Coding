#include<bits/stdc++.h>
using namespace std;

long long modRecursive(long long n,long long p,long long c)
{
    if(p == 0)
    {
        return 1;
    }
    else
    {
        if(p%2 == 0)
        {
            return modRecursive((n*n)%c,p/2,c);
        }
        else
        {
            return (n%c)*(modRecursive((n*n)%c,p/2,c)%c);
        }
    }
}

long long boringFact(long long n, long long p)
{
    long long res = -1;
    for(long long i = n+1; i < p ; i++)
    {
        res = ((res%p) * (modRecursive(i,p-2,p)%p))%p;
    }
    return (res+p);
}

int main() {

	// Write your code here
    int t;
    cin >> t;

    while(t--)
    {
        long long p,n;
        cin >> n >> p;
        if(n >= p)
        {
            cout<<0<<endl;
            continue;
        }
        else
        {
            cout<<boringFact(n,p)<<endl;
        }
    }

}