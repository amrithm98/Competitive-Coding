#include <bits/stdc++.h>
#define LL long long int
using namespace std;

LL maximumSum(vector <LL> a, LL m) {
    // Complete this function
    LL prefix = 0, max_sum = 0;
    set<LL> elems;
    elems.insert(0);
    
    for(int i = 0; i < a.size(); i++)
    {
        prefix = (prefix + a[i])%m;
        
        max_sum = max(max_sum,prefix);
        
        auto it = elems.upper_bound(prefix);
        if(it != elems.end())
            max_sum = max(max_sum, prefix - *it + m);
        
        elems.insert(prefix);
    }
    return max_sum;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        LL m;
        cin >> n >> m;
        vector<LL> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        LL result = maximumSum(a, m);
        cout << result << endl;
    }
    return 0;
}
