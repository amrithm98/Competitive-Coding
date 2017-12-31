#include<bits/stdc++.h>
using namespace std;

double calcSec(int b,int s,double p)
{
    int sec = 0;
    double temp = b/2.0;
    double str = temp + p*(s-temp);
    if(str > b)
        return 0;
    else
    {
        while(str <= b)
        {
            sec++;
            str += (p*(s-str));
        }
    }
    return sec;

} 

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int b,s;
        double p;
        cin >> s >> b;
        cin >> p;
        cout<<calcSec(b,s,p)<<endl;
        
    }
}