#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long long divisible41(string s)
{
    int len = s.length();
    if(len < 8)
    {
        return (stol(s)%41 == 0);
    }
    if(s == "0")
    {
        return 0;
    }

    if(len%5 !=0)
    {
        int bal = ((len/5)+1)*5-len;
        // cout<<bal<<" "<<len<<endl;
        for(int i = 1; i <=bal ; i++)
            s = "0"+s;
        len += bal;
    }

    int gsum = 0;

    while(len != 0)
    {
        string group = s.substr(len-5,5);
        len -= 5;
        long val = stol(group);
        gsum += val;
    }

    if(gsum >= 100000)
        return divisible41(to_string(gsum));
    else
        return (gsum%41 ==0);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a0,a1,c,n;
        cin >> a0 >> a1 >> c >> n;

        string s = "";
        s += to_string(a0);
        s += to_string(a1);
        for(int i = 2; i < n; i++)
        {
            s += to_string(((s[i-1]-'0')*c+(s[i-2]-'0'))%10);

        }
        if(divisible41(s))
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;
    }
    return 0;
}