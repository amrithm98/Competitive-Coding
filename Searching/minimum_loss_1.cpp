#include <bits/stdc++.h>
#define LL long long int
using namespace std;

int minimumLoss(vector <LL> price) {
    // Complete this function
    vector<pair<LL,int>> values;
    for(int i = 0; i < price.size(); i++)
        values.push_back(make_pair(price[i],i));
    sort(values.begin(),values.end());
    LL minDiff = INT_MAX;
    for(int i = 0; i < values.size()-1; i++)
    {
        if(values[i+1].first-values[i].first < minDiff && values[i+1].second < values[i].second)
        {
            minDiff = values[i+1].first-values[i].first;
        }
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
