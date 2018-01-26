#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int gcd(int a,int b)
{
    if(a < b)
    {
        return gcd(b,a);
    }
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

ll multiplesInRange(ll start,ll end,ll m)
{
    if(start % m == 0)
    {
        return ( (end/m - start/m) + 1 );
    }
    else
    {
        return (end/m - start/m);
    }   
}

int main()
{
    //Write your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        ll d;
        cin >> n >> m >> d;
        int lcm = (n*m)/gcd(n,m);

        ll mult_in_range = (lcm - m)/m + (lcm - n)/n + 1;
        ll beg = (d/mult_in_range)*lcm + 1;
        ll end = beg + lcm - 2;
        d = d % mult_in_range;
        
        while(beg <= end)
        {
            ll mid = (beg + end)/2;

            mult_in_range = multiplesInRange(beg,mid,m) + multiplesInRange(beg,mid,n);

            if(mult_in_range == d)
            {
                cout<<max((mid/m)*m,(mid/n)*n)<<endl;
                break;
            } 

            else if(mult_in_range < d)
            {
                d -= mult_in_range;
                beg = mid + 1;
            }

            else
            {
                end = mid;
            }
        }

    }

    return 0;
}