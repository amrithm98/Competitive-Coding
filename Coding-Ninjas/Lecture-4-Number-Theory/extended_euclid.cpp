#include <iostream>
#include <stdlib.h>
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
void multiplicativeModuloInverse(int a,int m)
{
    Triplet mmi = extendedEuclid(a,m);
    cout<<"\nMultiplicative Inverse is: "<<mmi.x<<endl;
}

int main()
{
    while(1)
    {
        cout<<"\n1. Extended Euclid: ";
        cout<<"\n2. Multiplicative Modulo Inverse: ";
        cout<<"\nChoice: ";
        int ch;
        cin>>ch;

        int a,b;
        cin >> a >> b;

        Triplet sol;
        
        switch(ch)
        {
            case 1:
                sol = extendedEuclid(a,b);
                cout<<"\nGCD: "<<sol.gcd;
                cout<<"\nSolution of ax+by = "<<sol.gcd<<" is (x,y): "<<sol.x<<" "<<sol.y<<endl;
                break;
            case 2:
                multiplicativeModuloInverse(a,b);
                break;
            default:
                exit(0);
        }

    }
    
    return 0;
}