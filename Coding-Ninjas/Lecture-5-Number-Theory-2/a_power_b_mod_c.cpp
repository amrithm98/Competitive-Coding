#include <iostream>
using namespace std;

int modRecursive_Iterative(int a, int b, int c)
{
    int ans = 1;
    while(b != 0)
    {
        // And with 1
        if(b&1)
        {
            ans = ((ans%c)*(a%c))%c;
        }
        a = ((a%c)*(a%c))%c;
        b = b/2;
    }
    return ans;
}

int recursiveMod(int a, int b, int c)
{
    if(b == 0)
        return 1;
    if( b % 2 == 0)
    {
        return recursiveMod((a*a)%c,b/2,c);
    }
    else
    {
        return ((a%c)*(recursiveMod((a*a)%c,b/2,c)))%c;
    } 
}

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout<<"Recursive: "<<recursiveMod(a,b,c)<<endl;
    cout<<"Iterative: "<<modRecursive_Iterative(a,b,c)<<endl;
    return 0;
}