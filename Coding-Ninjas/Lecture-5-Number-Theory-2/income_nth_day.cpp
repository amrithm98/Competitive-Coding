#include <iostream>
using namespace std;
#define MOD 1000000007
#define MOD1 1000000006

void multiply(long long a[2][2],long long m[2][2])
{
    long long f,g,h,i;

    f = ( (a[0][0] * m[0][0]) %MOD1 + (a[0][1] * m[1][0]) %MOD1 )%MOD1;
    g = ( (a[0][0] * m[0][1]) %MOD1 + (a[0][1] * m[1][1]) %MOD1 )%MOD1;
    h = ( (a[1][0] * m[0][0]) %MOD1 + (a[1][1] * m[1][0]) %MOD1 )%MOD1;
    i = ( (a[1][0] * m[0][1]) %MOD1 + (a[1][1] * m[1][1]) %MOD1 )%MOD1;
    
    a[0][0] = f;
    a[0][1] = g;
    a[1][0] = h;
    a[1][1] = i;
}

void APowerN(long long a[2][2],long long n)
{
    if(n == 1 || n == 0)
    {
        return;
    }

    APowerN(a,n/2);

    multiply(a,a);

    if(n%2 != 0)
    {
        long long m[2][2] = {{1,1},{1,0}};
        multiply(a,m);
    }

}

long long modRecursive(long long w,long long x)
{
    if(x == 0)
    {
        return 1;
    }
    long long result = modRecursive(w,x/2);
    result = (result*result)%MOD;
    if(x%2 == 1)
    {
        result = (result*(w%MOD))%MOD;
    }
    return result;
}

long long income_nth_day(long long w,long long x,long long n)
{
    //a->w b->x
    long long f[2][2] = {{1,1},{1,0}};
    
    // cout<<"\nF1 & F2: "<<f1<<" "<<f2<<endl;
    APowerN(f,n-1);
    // cout<<"\nF1 & F2: "<<f1<<" "<<f2<<endl;
    return (modRecursive(w,f[0][1])*modRecursive(x,f[0][0]))%MOD;
}

int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--)
    {
        long long a,b,n;
        cin >> a >> b >> n;

        if( n == 0)
        {
            cout<<a%MOD1<<endl;
            continue;
        }
        if( n == 1)
        {
            cout<<b%MOD1<<endl;
            continue;
        }

        a = (a+1);
        b = (b+1);

        // cout<<"\nA & B: "<<a<<" "<<b<<endl;
        cout<<income_nth_day(a,b,n)-1<<endl;
        // cout<<nth_fibonacci(1)<<" "<<nth_fibonacci(2)<<" "<<nth_fibonacci(5)<<" ";
    }
}