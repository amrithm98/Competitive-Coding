#include <iostream>
using namespace std;

int dp[101][3];
int n;

int solve(int *arr,int curr,int prev)
{
    if(curr == n)
    {
        return 0;
    }

    if(dp[curr][prev] != -1)
    {
        return dp[curr][prev];
    }

    int result ;

    if(arr[curr] == 0)
    {
        return 1 + solve(arr,curr+1,0);
    }
    else if(arr[curr] == 1)
    {
        if(prev != 1)
        {
            result = min(1+solve(arr,curr+1,0),solve(arr,curr+1,1));
        }else
        {
            result = 1 + solve(arr,curr+1,0);
        }
    }
    else if(arr[curr] == 2)
    {
        if(prev != 2)
        {
            result = min(1 + solve(arr,curr+1,0),solve(arr,curr+1,2));
        }else
        {
            result = 1 + solve(arr,curr+1,0);
        }
    }
    else
    {
        if(prev == 0)
        {
            int ans1 = 1 + solve(arr,curr+1,0);
            int ans2 = solve(arr,curr+1,1);
            int ans3 = solve(arr,curr+1,2);
            result = min(ans1,min(ans2,ans3));
        }
        else if(prev == 2)
        {
            int ans1 = 1 + solve(arr,curr+1,0);
            int ans2 = solve(arr,curr+1,1);
            result = min(ans1,ans2);
        }
        else
        {
            int ans1 = 1 + solve(arr,curr+1,0);
            int ans2 = solve(arr,curr+1,2);
            result = min(ans1,ans2);
        }
    }

    dp[curr][prev] = result;

    return result;
}

int main()
{
    cin >> n;
    int *arr = new int[n+1];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<solve(arr,0,0)<<endl;

    return 0;
}

