#include <bits/stdc++.h>

using namespace std;

int prime(unsigned long long int n)
{
    long lim = sqrt(n)+1;
    for(int i = 3; i <= lim; i++)
    {
        if(n % i == 0)
        {
            return i;
        }
    }
    return 0;
}

unsigned long long int getDivisions(unsigned long long int n)
{
    // cout<<n<<"\n Called";
    if(n == 1)
        return 1;

    unsigned long long int temp = n;
    if(temp % 2 == 0)
    {
        unsigned long long int sum = 0;
        while(n % 2 == 0)
        {
            sum += n;
            n /= 2;
        }
        int ans = 0;
        // cout<<"\nIntermed n "<<n<<endl;
        if(n!=1)
            sum += n;
        while(prime(n) > 0 && n > 1)
        {
            ans = prime(n);
            sum += n/ans;
            n = n/ans;
            // cout<<"\nFirst Divisor of oddd: "<<ans<<endl;
        }
        sum += 1;
        return sum;
    }
    else if(prime(n) == 0)
    {
        return n+1;
    }
    else
    {
        unsigned long long int sum = 0;
        n = temp;
        sum += n;
        // cout<<"CALLING : "<<temp<<endl;
        int ans = 0;
        
        while(prime(n) > 0 && n > 1)
        {
            // cout<<"\nPRIME CHECKING: "<<n<<endl;
            ans = prime(n);
            sum += n/ans;
            n = n/ans;
            // cout<<"\nFirst Divisor of oddd: "<<ans<<endl;
        }
        sum += 1;
        return sum;
    }
}

unsigned long long int longestSequence(vector <unsigned long long int> a) {
    //  Return the length of the longest possible sequence of moves.
    unsigned long long int sum = 0;
    for(int i = 0; i < a.size() ; i++)
    {
        unsigned long long int n = a[i];
        unsigned long long int ans = getDivisions(n);
        // cout<<ans<<endl;
        sum += ans;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<unsigned long long int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    // boolSieve = sieve_of_eratosthenes();
    unsigned long long int result = longestSequence(a);
    cout << result << endl;
    return 0;
}
