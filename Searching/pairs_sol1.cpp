#include <bits/stdc++.h>
#define LL long long int
using namespace std;

LL pairs(int k, vector <LL> arr) 
{
    // Complete this function
    unordered_set<LL> freq;
    for(int i = 0; i < arr.size(); i++)
            freq.insert(arr[i]);
    
    LL count = 0;
    unordered_set<LL>:: iterator it;
    for(it = freq.begin(); it != freq.end();)
    {
        if(freq.find(*it-k) != freq.end())
        {
            count++;
        }
        if(freq.find(*it+k) != freq.end())
        {
            count++;
        }
        freq.erase(*it);
        it = freq.begin();
    }
    return count;
    
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<LL> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = pairs(k, arr);
    cout << result << endl;
    return 0;
}
