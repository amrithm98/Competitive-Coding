#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cint >> t;
    while(t--)
    {
        int a,n,p;

        cin >> a >> n >> p;

        if(a == 1)
        {
            cout << a%p <<endl;
            continue;
        }
        int i = 1;
        
        while(i <= n)
        {
            if(pow(a,i) % p ==0)
            {
                cout<<0<<endl;
                break;
            }
            else
            {
                int rem = a % p;
            }
        }
        


    }
}