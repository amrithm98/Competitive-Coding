#include <iostream>
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

int main()
{
    int a,b;
    cin >> a >> b;

    Triplet sol = extendedEuclid(a,b);
    cout<<"\nGCD: "<<sol.gcd;
    cout<<"\nSolution of ax+by = "<<sol.gcd<<" is (x,y): "<<sol.x<<" "<<sol.y<<endl;
    return 0;
}