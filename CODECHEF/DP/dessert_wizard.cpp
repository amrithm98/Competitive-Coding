#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL solve(LL *arr, int n)
{
    LL leftToRight[10001][2],rightToLeft[10001][2];

    for(int i = 0; i < n; i++)
    {
        leftToRight[i][0] = 0;
        leftToRight[i][1] = 0;
        rightToLeft[i][0] = 0;
        rightToLeft[i][1] = 0;
    }

    leftToRight[0][0] = arr[0];
    leftToRight[0][1] = arr[0];

    for(int i = 1; i < n; i++)
    {
        leftToRight[i][0] = max(0LL,leftToRight[i-1][0]) + arr[i];
        leftToRight[i][1] = min(0LL,leftToRight[i-1][1]) + arr[i];
    }

    rightToLeft[n-1][0] = arr[n-1];
    rightToLeft[n-1][1] = arr[n-1];

    for(int i = n-2; i >= 0; i--)
    {
        rightToLeft[i][0] = max(0LL,rightToLeft[i+1][0]) + arr[i];
        rightToLeft[i][1] = min(0LL,rightToLeft[i+1][1]) + arr[i];
    }   
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << leftToRight[i][0] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << leftToRight[i][1] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << rightToLeft[i][0] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << rightToLeft[i][1] << " ";
    }
    cout << endl;

    LL ans = 0;

    for(int i = 0; i < n-1; i++)
    {
        ans = max(ans,abs(leftToRight[i][0] - rightToLeft[i+1][1]));
        ans = max(ans,abs(leftToRight[i][1] - rightToLeft[i+1][0]));
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        LL *delish = new LL[n];
        for(int i = 0; i < n; i++)
        {
            cin >> delish[i];
        }
        cout << solve(delish,n) << endl;
    }
    
    return 0;
}
