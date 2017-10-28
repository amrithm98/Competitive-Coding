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
            cout<<"NO"<<endl;
            continue;
        }
        string s = "";
        s += to_string(a0);
        s += to_string(a1);
        for(int i = 2; i < n; i++)
        {
            s += to_string(((s[i-1]-'0')*c+(s[i-2]-'0'))%10);
        }
        long long aModb = 0;
        for(int i = 0; i < s.size(); i++)
        {
            aModb = ((10*aModb) + (int)(s[i]-'0'))%41;
        }
        if(aModb == 0)
            cout<<"YES";
        else 
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}