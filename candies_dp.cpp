#include <bits/stdc++.h>

using namespace std;

long long candies(int n, vector <int> arr) {
    // Complete this function
    vector<long long> dp(n);
    dp[0] = 1;

    for(int i = 1; i < n; i++)
        dp[i] = 1;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > arr[i-1])
            dp[i] = dp[i-1] + 1;
    }

    for(int i = n-2 ; i >= 0 ; i--)
    {
        if(arr[i] > arr[i+1])
        {
            dp[i] = max(dp[i],dp[i+1] + 1);
        }
    }
    long long sum = 0;

    for(int i = 0; i < n; i++)  
        sum += dp[i];

    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long long result = candies(n, arr);
    cout << result << endl;
    return 0;
}
