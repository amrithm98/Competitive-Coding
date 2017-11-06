#include <iostream>
using namespace std;
#define MOD 1000000007

void multiply(unsigned long long a[2][2],unsigned long long m[2][2])
{
    unsigned long long f,g,h,i;

    f = ( (a[0][0]%MOD * m[0][0]%MOD) %MOD + (a[0][1]%MOD * m[1][0]%MOD) %MOD )%MOD;
    g = ( (a[0][0]%MOD * m[0][1]%MOD) %MOD + (a[0][1]%MOD * m[1][1]%MOD) %MOD )%MOD;
    h = ( (a[1][0]%MOD * m[0][0]%MOD) %MOD + (a[1][1]%MOD * m[1][0]%MOD) %MOD )%MOD;
    i = ( (a[1][0]%MOD * m[0][1]%MOD) %MOD + (a[1][1]%MOD * m[1][1]%MOD) %MOD )%MOD;
    
    a[0][0] = f;
    a[0][1] = g;
    a[1][0] = h;
    a[1][1] = i;

}

void APowerN(unsigned long long a[2][2],unsigned long long n)
{
    if(n == 1 || n == 0)
    {
        return;
    }

    APowerN(a,n/2);

    multiply(a,a);

    if(n%2 != 0)
    {
        unsigned long long m[2][2] = {{1,1},{1,0}};
        multiply(a,m);
    }

}

unsigned long long fib(unsigned long long n)
{
    unsigned long long a[2][2] = {{1,1},{1,0}};
    if( n == 0)
    {
        return 0;
    }
    APowerN(a,n-1);
    return a[0][0];
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{

    return ( (fib(n+2)%MOD - fib(m+1)%MOD + MOD) % MOD );
}

int main()
{
    int n,m;
    cin >> n >> m;
    cout<<fiboSum(m,n)<<endl;
}
