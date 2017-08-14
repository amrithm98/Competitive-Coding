#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

bool isKaprekar(int i,long n)
{
    bool status=false;
    long temp=i;
    int count=0;
    while(temp!=0)
    {
        int d=temp%10;
        temp/=10;
        count++;
    }
    int ten_pow_count=pow(10,count);
    int r_half=n%ten_pow_count;
    int l_half=n/ten_pow_count;
    if((l_half+r_half)==i)
    {
        status=true;
    }
    else
    {
        status=false;
    }
    return status;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long p,q;
    cin>>p;
    cin>>q;
    int flag=0;
    for(long i=p;i<=q;i++)
    {
        ll sqr=i*i;
        if(isKaprekar(i,sqr))
        {
            flag=1;
            cout<<i<<" ";
        }
    }
    if(!flag)
    {
        cout<<"INVALID RANGE";
    }
    return 0;
}
