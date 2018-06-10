#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<long long> fib(100002);

void fibonacci()
{
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= 100001; i++)
    {
        fib[i] = (fib[i-1] + fib[i-2])%MOD;
    }
}

int main()
{
    int t;
    cin >> t;

    fibonacci();

    while(t--)
    {
        int m,n;
        cin >> m >> n;

        long long sum = 0;

        vector<long long> arr(m),brr(m);

        for(int i = 0; i < m; i++)
        {
            long long x;
            cin >> x;

            if(n == 1)
            {
                arr[i] = x;
            }
            else
                arr[i] = (fib[n-2]*x)%MOD;
            sum  = ( sum + arr[i] )%MOD;
        }

        for(int i = 0; i < m; i++)
        {
            long long x;
            cin >> x;

            if(n == 1)
            {
                brr[i] = 0;
            }
            else
                brr[i] = (fib[n-1]*x)%MOD;

            sum  = ( sum + brr[i] )%MOD;
        }   

        // for(int i = 0; i < m; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < m; i++)
        // {
        //     cout << brr[i] << " ";
        // }
        // cout << endl;
        sum = (sum*m)%MOD;
        cout << sum << endl;
    }

    return 0;
}