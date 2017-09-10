#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        int k;
        cin >> n >> m >> k;
        vector< vector<int> > h(n,vector<int>(m));
        for(int h_i = 0;h_i < n;h_i++){
           for(int h_j = 0;h_j < m;h_j++){
              cin >> h[h_i][h_j];
           }
        }
        // Write Your Code Here
    }
    return 0;
}
