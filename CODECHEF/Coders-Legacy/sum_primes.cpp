#include <bits/stdc++.h>
using namespace std;

vector<bool> siv(100002,true);

vector<int> primes()
{
    vector<int> p;

    siv[0] = 0;
    siv[1] = 1;

    for(int i = 2; i*i <= 100001; i++)
    {
        if(siv[i])
            for(int j = i*i; j <= 100001; j += i)
                siv[j] = false;
    }

    for(int i = 2; i <= 100001; i++)
        if(siv[i])
            p.push_back(i);

    return p;

}
int main()
{
    vector<int> sieve = primes();

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        int max_pairs = -1;

        for(int i = 0; sieve[i] <= n; i++)
        {
            if(n % sieve[i] == 0 && n/sieve[i] == 2)
            {
                max_pairs++;
            }
            if(siv[n-sieve[i]])
            {
                max_pairs++;
            }
        }
        
        cout << max_pairs << endl;
    }

    return 0;
}