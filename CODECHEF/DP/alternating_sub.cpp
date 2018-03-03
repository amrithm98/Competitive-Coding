#include <bits/stdc++.h>
using namespace std;
#define LL long long int

bool altSign(LL n,LL m)
{
    return (n*m)<0;
}

/**
void longestAlternating(LL *arr, int n)
{
    int *dp = new int[n];

    for(int i = 0; i < n; i++)
        dp[i] = 1;

    for(int i = 0; i < n; i++)
    {
        int num = arr[i];
        for(int j = i+1; j < n; j++)
        {
            if(altSign(num,arr[j]))
            {
                dp[i]++;
                num = arr[j];
            }
            else
            {
                break;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        cout << dp[i] << " ";
}
**/

void altSubOptim(LL *arr,int n)
{
    int *dp = new int[n];

    for(int i = 0; i < n; i++)
        dp[i] = 1;
    

    for(int i = n-2; i >= 0; i--)
    {   
        LL num = arr[i];
        if(altSign(arr[i+1],num))
        {
            dp[i] = dp[i+1]+1;
        }
        else
        {
            dp[i] = 1;
        }
    }

    for(int i = 0; i < n; i++)
        cout << dp[i] << " ";
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

        altSubOptim(arr,n);
        cout << endl;
    }

    return 0;
}