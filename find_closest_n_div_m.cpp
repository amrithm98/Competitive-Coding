#include<iostream>
using namespace std;
int findClosestNum(int n,int m)
{
    int q,n1,n2;
    q=n/m;
    n1=q*m;

    if(n*m>0)
        n2=(m*(q+1));
    else    
        n2=(m*(q-1));
    
    // cout<<q<<"\t"<<n1<<"\t"<<n2;

    if(abs(n-n1)<abs(n-n2))
        return n1;
    else    
        return n2;

    
}
int main()
{
    int n,m;
    cin>>n>>m;

    cout<<"\n"<<findClosestNum(n,m);
}