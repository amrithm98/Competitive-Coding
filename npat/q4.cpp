#include <iostream>

using namespace std;

int max3(int x, int y, int z) {
    if(x >= y) 
    {
        if(x>=z)
            return x;
    } 
    else if(y >= z) 
    {
        return y;
    } 
    return z;
}
int main()
{
    cout<<max3(1,2,3);
    cout<<max3(3,2,1);
    cout<<max3(1,1,1);
    cout<<max3(1,3,2);
}