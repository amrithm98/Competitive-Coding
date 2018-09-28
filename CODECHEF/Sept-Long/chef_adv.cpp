#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long n,m,x,y;
        cin >> n >> m >> x >> y;

        n--;
        m--;

        if(n%x == 0 && m%y == 0)
        {
            cout << "Chefirnemo\n";
        }
        else if(n > 0 && m > 0 && (n-1)%x == 0 && (m-1)%y == 0)
        {
            cout << "Chefirnemo\n";
        }
        else
            cout << "Pofik\n";
    }
    return 0;
}