#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calc_lis(vector<int> val,int n)
{
    vector<int> lis(n);

    int i=0,j=0;

    for(;i<n;i++)
        lis[i]=1;

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(val[j]<val[i] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }

    int max=lis[0];
    for(i=1;i<n;i++)
        if(max<lis[i])
            max=lis[i];

    return max;

    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;

    vector<int> val(n);

    for(int i=0;i<n;i++)
        cin>>val[i];

    cout<<calc_lis(val,n);
    return 0;
}
