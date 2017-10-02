#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    long t;
    cin>>t;
    for(long i=0;i<t;i++)
    {
        long x1,y1,x2,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;
        long xDiff=x2-x1,yDiff=y2-y1;
        long val=abs(xDiff)+abs(yDiff);
        if(val<=k)
            cout<<"YES\n";
        else    
            cout<<"NO\n";
    }
    return 0;
}
