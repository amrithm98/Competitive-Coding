#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sum_as_nth_pow(int num,int power,int base,int sum)
{
    int curr=pow(base,power);
    
    if((curr+sum)==num)
        return 1;
    if(sum>num || curr>num)
        return 0;
    else
    {
        return sum_as_nth_pow(num,power,base+1,sum+curr)+sum_as_nth_pow(num,power,base+1,sum);
    }
}

int main() {
    /* Enter your cootherotherotherde here. Read input from STDIN. Print output to STDOUT */   
    int x,n;
    cin>>x;
    cin>>n;
    cout<<sum_as_nth_pow(x,n,1,0)<<endl;
    return 0;
}
