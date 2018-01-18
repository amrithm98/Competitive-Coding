#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long int steps(int x,int y,int a,int b,int steps=0)
{
    cout<<"\nX : Y"<<x<<" "<<y<<endl;

    if(x > a || y > b)
    {
        return INT_MAX;
    }

    if(x == a && y == b)
    {   
        return steps;
    }

    int ans1 = steps(x+y,y,a,b,steps+1);
    int ans2 = steps(x,x+y,a,b,steps+1);

    return 1 + min(ans1,ans2);
}

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        int a,b;
        cin >> a >> b;

        cout<<steps(1,1,a,b)<<endl;
    }
}