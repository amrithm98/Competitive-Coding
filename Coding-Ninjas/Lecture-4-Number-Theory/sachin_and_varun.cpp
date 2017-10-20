#include<iostream>
using namespace std;

class Triplet
{
    public:
        int gcd,x,y;
};

Triplet extendedEuclid(int a,int b)
{
    if(b == 0)
    {
        Triplet base;
        base.gcd = a;
        base.x = 1;
        base.y = 0;
        return base;
    }

    Triplet smallOutput = extendedEuclid(b,a%b);
    Triplet answer;
    answer.gcd = smallOutput.gcd;
    answer.x = smallOutput.y;
    answer.y = (smallOutput.x - (a/b)*smallOutput.y);

    return answer;
}

int multiplicativeModuloInverse(int a,int m)
{
    Triplet mmi = extendedEuclid(a,m);
    long long modInv = (mmi.x % m + m)%m;
    return modInv;
}


long long gcd(long long a,long long b)
{
    if(a<b)
        return gcd(b,a);
    
    if(b == 0)
        return a;

    else    
        return gcd(b,a%b);
}

int main(){
	// Write your code here
    int t;
    cin >> t;
    while(t--)
    {
        long long a,b,d;
        cin >> a >> b >> d;
        
        long long g = gcd(a,b);
        a /= g;
        b /=g;

        if(d%g != 0)
        {
            cout<<0<<endl;
            continue;
        }

        if(d == 0)
        {
            cout<<1<<endl;
            continue;
        }

        d /= g;

        long long y1 = ((d%a)*multiplicativeModuloInverse(b,a))%a;

        if(d < y1*b)
        {
            cout<<0<<endl;
            continue;
        }

        long long n = ((d/b)-y1)/a;

        cout<< n+1 <<endl;

    }
	return 0;
}