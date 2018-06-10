#include <bits/stdc++.h>
using namespace std;

long long int maxXorSum(long long int n, int k)
{

    if (k == 1)
        return n;
 
    int res = 1;
    while (res <= n)
    {
        res <<= 1;
    }

    return res - 1;
}


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        long long int k;
        cin >> n >> k;

        cout << maxXorSum(k,n) << endl;
        
    }

    return 0;
}