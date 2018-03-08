// arr - input array
// n - size of array
#include <bits/stdc++.h>
using namespace std;

int minAbsoluteDiff(int arr[], int n) {

    sort(arr,arr+n);
    int minDiff = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        if(abs(arr[i]-arr[i-1]) < minDiff)
            minDiff = arr[i]-arr[i-1];
    }
    return minDiff;
}
