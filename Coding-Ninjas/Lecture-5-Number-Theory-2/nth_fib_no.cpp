#include<iostream>
using namespace std;
#define MOD 1000000007
void multiply(long long a[2][2],long long m[2][2])
{
    long long f,g,h,i;

    f = ((a[0][0]*m[0][0])%MOD + (a[0][1]*m[1][0])%MOD)%MOD;
    g = ((a[0][0]*m[0][1])%MOD + (a[0][1]*m[1][1])%MOD)%MOD;
    h = ((a[1][0]*m[0][0])%MOD + (a[1][1]*m[1][0])%MOD)%MOD;
    i = ((a[1][0]*m[0][1])%MOD + (a[1][1]*m[1][1])%MOD)%MOD;
    
    a[0][0] = f;
    a[0][1] = g;
    a[1][0] = h;
    a[1][1] = i;
}

void APowerN(long long a[2][2],long long n)
{
    if( n == 0 || n == 1)
    {
        return;
    }

    APowerN(a,n/2);

    multiply(a,a);

    if((n%2)!=0)
    {
        long long M[2][2] = {{1,1},{1,0}};
        multiply(a,M);
    }
}

long long nthFibonacci(long long n)
{
    long long a[2][2];
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    
    if(n == 0)
    {
        return 0;
    }

    APowerN(a,n-1);

    return a[0][0];
}

int main()
{
    long long n;
    cin >> n ;
    cout<< nthFibonacci(n)%1000000007 <<endl;
}