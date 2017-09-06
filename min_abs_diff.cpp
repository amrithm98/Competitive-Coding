#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

long long minimumAbsoluteDifference(long long n, vector <long long> arr) {
    // Complete this function
    long long min=INT8_MAX;
    sort(arr.begin(),arr.end());
    for(long long i=0;i<n-1;i++)
    {
        long long diff=abs(arr[i]-arr[i+1]);
        if(diff<=min)
            min=diff;
    }
    return min;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for(long long arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long long result = minimumAbsoluteDifference(n, arr);
    cout << result << endl;
    return 0;
}