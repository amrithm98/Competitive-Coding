#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    long long int *arr = new long long int[n+1];
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr,arr+n+1);

    long long int *sum = new long long int[n+1];
    sum[1] = arr[1];

    //Array Storing Cumulative Sums
    for(int i = 2; i <=n ; i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }

    long long int target = 0;
    //Calculating Cost for 1st k elements
    for(int i = 2; i <= k; i++)
    {
        target += ( ((i-1)*arr[i]) - sum[i-1] );
    }
    long long int min_target = target; 

    //Calculating Cost for next possible k-consecutive blocks using formulae
    //Then find the least cost k-consecutive block
    //new_cost = old_cost - 2(x2+...+xk) + (k-1)(x[i-1]) + (k-1)(x[i+1])

    for(int i = 2; i <= n-k+1 ; i++)
    {
        target = target - 2*(sum[i+k-2] - sum[i-1]) + (k-1)*arr[i-1] + (k-1)*arr[i+k-1];
        if(target < min_target)
            min_target = target;
    }

    cout<<min_target<<endl;
    return 0;
}
