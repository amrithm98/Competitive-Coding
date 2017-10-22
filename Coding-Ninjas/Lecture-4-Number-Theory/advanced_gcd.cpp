#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(long long a,long long b)
{
    if(a<b)
        return gcd(b,a);

    if(b == 0)
        return a;

    else
        return gcd(b,a%b);

}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a,b;
        cin >> a >> b;

        string big;
        long long small;

        if(a.size()>b.size())
        {
            big = a;
            small = stoll(b);
        }
        else
        {
            big = b;
            small = stoll(a);
        }

        long long aModb = 0;

        if(small == 0)
        {
          cout<<big<<endl;
          continue;
        }
      
        for(int i = 0; i < big.size();i++)
        {
            aModb = ((10*aModb) + (int)(big[i]-'0'))%small;
        }
      
		if(aModb == 0)
        {
          cout<<small<<endl;
          continue;
        }
      
        cout<<gcd(small,aModb)<<endl;
    }	
    return 0;
}