#include<iostream>
using namespace std;

void multiply(int a[2][2],int m[2][2])
{
    int f,g,h,i;

    f = a[0][0]*m[0][0] + a[0][1]*m[1][0];
    g = a[0][0]*m[0][1] + a[0][1]*m[1][1];
    h = a[1][0]*m[0][0] + a[1][1]*m[1][0];
    i = a[1][0]*m[0][1] + a[1][1]*m[1][1];
    
    a[0][0] = f;
    a[0][1] = g;
    a[1][0] = h;
    a[1][1] = i;
}

void APowerN(int a[2][2],int n)
{
    if( n == 0 || n == 1)
    {
        return;
    }

    APowerN(a,n/2);

    multiply(a,a);

    if((n%2)!=0)
    {
        int M[2][2] = {{1,1},{1,0}};
        multiply(a,M);
    }
}

int nthFibonacci(int n)
{
    int a[2][2];
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
    int n;
    cin >> n ;
    cout<< nthFibonacci(n) <<endl;
}