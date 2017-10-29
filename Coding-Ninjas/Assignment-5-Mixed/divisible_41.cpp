#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a0,a1,c,n;
        cin >> a0 >> a1 >> c >> n;
        if( n <= 1)
        {
            if(n == 1 && a0 !=0)
                cout<<"NO"<<endl;
            else if(n == 1 && a0 ==0)
                cout<<"YES"<<endl;
            else if (n ==0)
                cout<<"YES"<<endl;
            continue;
        }
        long long aModb = 0;

        aModb = a0;
        aModb = (10*a0+a1)%41;
        for(int i = 2; i < n; i++)
        {
            int a2 = ((a1*c) + (a0))%10;
            aModb = (10*aModb + a2)%41;
            a0 = a1;
            a1 = a2;
        }
        

        if(aModb == 0)
            cout<<"YES";
        else 
            cout<<"NO";

        cout<<endl;
    }
    return 0;
}