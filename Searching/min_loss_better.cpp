#include <bits/stdc++.h>
#define LL long long int
using namespace std;

int minimumLoss(vector <LL> price) {
    // Complete this function
    set<LL> freq;
    freq.insert(price[0]);
    LL minDiff = INT_MAX;
    for(int i = 1; i < price.size(); i++)
    {
        if(freq.upper_bound(price[i]) != freq.end())
        {
            minDiff = min(minDiff,*freq.upper_bound(price[i]) - price[i]);
        }
        freq.insert(price[i]);
    }
    
    return minDiff;
}

int main() {
    int n;
    cin >> n;
    vector<LL> price(n);
    for(int price_i = 0; price_i < n; price_i++){
       cin >> price[price_i];
    }
    LL result = minimumLoss(price);
    cout << result << endl;
    return 0;
}
