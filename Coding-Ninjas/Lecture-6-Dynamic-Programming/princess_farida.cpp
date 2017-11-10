#include <bits/stdc++.h>
using namespace std;

long long max_coins(long long *input,int n)
{
    long long *output = new long long[n];
    output[0] = input[0];
    for(int i = 1; i < n; i++)
    {
        output[i] = input[i];
        long long possAns = 0;
        for(int j = i-2; j >= 0; j--)
        {   
            if(input[j] > possAns)
                possAns = input[j];
        }
        output[i] += possAns;
    }
    for(int i = 0; i < n; i++)
        cout<<output[i]<<" ";
    return 1;
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
