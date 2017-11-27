#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 1000001

vector<long> cubeDivisors()
{ 
    vector<int> cubeDivisor(MAX);
    vector<long> cubesUptoN(MAX);
    for(long i = 2;i <= cbrt(MAX);i++)
    {
        long k = i*i*i;
        for(long j = i*i*i; j <= MAX ; j += k)
        {
            cubeDivisor[j] = 1;
        }

    }
    
    for(long i = 1; i <= MAX; i++)
    {
        cubesUptoN[i] = cubesUptoN[i-1] + cubeDivisor[i];
    }

    return cubesUptoN;
}
int main()
{
	// Write your code here

    int t,t0 = 1;
    cin >> t;
    vector<long> cubes;
    cubes = cubeDivisors();
    while(t0 <= t)
    {
        long long n;
        cin >> n;

        if(cubes[n]-cubes[n-1] != 1)
            cout<<"Case "<<t0<<":"<<" "<<n-cubes[n]<<endl;
        else    
            cout<<"Case "<<t0<<":"<<" Not Cube Free"<<endl;
        t0++;
    }
	return 0;
}