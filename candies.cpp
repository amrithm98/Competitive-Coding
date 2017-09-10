#include <bits/stdc++.h>

using namespace std;

int candies(int n, vector <int> arr) {
    // Complete this function
    
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = candies(n, arr);
    cout << result << endl;
    return 0;
}
