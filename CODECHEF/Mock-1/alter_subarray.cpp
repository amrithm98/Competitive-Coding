#include <bits/stdc++.h>
using namespace std;

#define LL long long int

bool altSign(LL a, LL b)
{
    return ((a*b) < 0);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        LL *arr = new LL[n];
        
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int *dp = new int[n];

        for(int i = 0; i < n; i++)
            dp[i] = 1;

        for(int i = n-2; i >= 0; i--)
        {   
            if(altSign(arr[i],arr[i+1]))
            {
                dp[i] = dp[i+1]+1;
            }
        }

        for(int i = 0; i < n; i++)
            cout << dp[i] << " ";
        
        cout << endl;
    }
}