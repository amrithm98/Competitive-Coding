#include<bits/stdc++.h>
using namespace std;

int countCodes(int *arr,int size)
{
    if(size == 0 || size == 1)
        return 1;
    int output = countCodes(arr,size - 1);
    if(arr[size - 2]*10 + arr[size - 1] <=26)
        output += countCodes(arr,size - 2);
    return output;
}

int countCodes_dp(int *arr,int size,int *dp)
{
    if(size == 0 || size == 1)
        return 1;

    if(dp[size] > 0)
        return dp[size];

    int output = countCodes_dp(arr,size - 1,dp);

    if(arr[size - 2]*10 + arr[size - 1] <=26)
        output += countCodes_dp(arr,size - 2,dp);

    dp[size] = output;
    return output;
}

int countCodes_iter(int *arr,int size)
{
    int *output = new int[size+1];
    output[0] = 1;
    output[1] = 1;
    for(int i = 2; i <= size ; i++)
    {
        output[i] = output[i-1];
        if(arr[i-2]*10+arr[i-1] <= 26)
            output[i] += output[i-2];
    }
    int ans = output[size];
    delete [] output;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int *dp = new int[n+1];
    for(int i = 0 ; i < n; i++)
    {   
        int a;
        cin >> a;
        arr[i] = a;
        dp[i] = 0;
    }
    cout<<countCodes(arr,n)<<endl;
    cout<<countCodes_dp(arr,n,dp)<<endl;
    cout<<countCodes_iter(arr,n)<<endl;
    return 0;
}