#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> arr(n),primes(m);
    for(int i = 0; i < n; i++)  
        cin >> arr[i];

    for(int i = 0; i < m; i++)
        cin >> primes[i];

    int rand_count = 10;
    long long max_op = 0;

    while(rand_count--)
    {
        vector<long long> prodModM(m,1);
        long long prod = 1;
        for(int i = 0; i < n; i++)
        {
            long long num = arr[i] + rand()%10;
            for(int j = 0; j < m; j++)
            {
                prodModM[j] = (prodModM[j]*num)%primes[j];
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < m; i++)
            ans += (prodModM[i]);

        cout << ans/m << endl;
        max_op = max(max_op,ans/m);

    }

    cout << max_op << endl;
    return 0;
}