#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    long t;
    cin>>t;
    for(long i=0;i<t;i++)
    {
        long x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        long xDiff=x2-x1,yDiff=y2-y1;
        if(abs(xDiff)==abs(yDiff))
            cout<<1<<endl;
        else if((abs(x2-x1)+abs(y2-y1))%2==0)
        {
              cout<<2<<endl;
        } 
        else
        {
              cout<<-1<<endl;
        }
    }
    return 0;
}
