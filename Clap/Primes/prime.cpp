#include <bits/stdc++.h>
using namespace std;


vector<int> primes()
{
    vector<bool> sieve(100009,1);
    vector<int> pr;

    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2; i*i < 100009; i++)
    {
        if(sieve[i])
            for(int j = i*i; j < 100009; j+= i)
                sieve[j] = false;
    }

    for(int i = 0; i < sieve.size(); i++)
        if(sieve[i])
            pr.push_back(i);

    return pr;
}
int main()
{

    ifstream in("ip2.txt");
    ofstream out("output.txt");

    int t;
    in >> t;
    vector<int> prime = primes();

    while(t--)
    {
        int n;
        in >> n;

        for(int i = 0; i < n; i++)
            out << prime[i] << " ";

        out << "\n";
    }

    return 0;
}