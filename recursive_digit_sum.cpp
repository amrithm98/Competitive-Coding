#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int superDigit(long long int n,long long int k)
{
    if(n/10==0)
    {
        return n;
    }
    long long int digSum=0;
    long long int temp=n;
    while(temp!=0)
    {
        digSum+=temp%10;
        temp/=10;
    }
    digSum*=k;
    cout<<digSum<<endl;
    return superDigit(digSum,1);
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long int n,k;
    cin>>n>>k;
    cout<<superDigit(n,k)<<endl;
    return 0;
}
