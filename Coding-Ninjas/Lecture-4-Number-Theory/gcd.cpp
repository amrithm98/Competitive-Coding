#include <iostream>
using namespace std;


int gcd(int a,int b)
{
	//Write your code here
    if(a < b)
        return gcd(b,a);

    if(b == 0)
        return a;
        
    else
        return gcd(b,a%b);
}

int main()
{
    int a,b;
    cin >>a >>b;
    cout<<gcd(a,b)<<endl;
}