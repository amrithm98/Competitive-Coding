#include <bits/stdc++.h>
using namespace std;

long long max_coins(long long *input,int n)
{
    long long *output = new long long[n];
    output[0] = input[0];
    output[1] = max(input[0],input[1]);
    for(int i = 2; i < n; i++)
    {
        //Exclude ith element(then output[i] = output[i-1])
        //or include ith element(then we can't include i-1th element)
        output[i] = max(output[i-1],output[i-2] + input[i]);
    }
    return output[n-1];
}

int main()
{
    int t;
    cin >> t;
    int t0 = 1;
    while(t0 <= t)
    {
        int n;
        cin >> n;
        long long *input = new long long[n];
        for(int i = 0; i < n; i++)
            cin >> input[i];
        cout<<"Case "<<t0<<": "<<max_coins(input,n)<<endl;
        t0++;
    }
    return 0;
}
