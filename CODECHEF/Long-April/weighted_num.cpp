#include <bits/stdc++.h>
using namespace std;

#define LL long long int

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

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        LL n;
        int w;
        cin >> n >> w;
        if(abs(w) <= 9)
        {
            int num_pairs = 0;
            for(int i = 1; i <= 9; i++)
            {
                for(int j = 0; j <= 9; j++)
                    if(j-i == w)
                        num_pairs++; 
            }
            LL modVal = modRecursive(10,n-2,1000000007);
            LL ans = ((long long int)(num_pairs)*modVal)%1000000007;
            cout << ans << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}