#include <bits/stdc++.h>

using namespace std;

string feeOrUpfront(int n, int k, int x, int d, vector <int> p) {
    // Complete this function
    float i,j,sum=0;
    vector<float> interests(n);
    for(int i=0;i<n;i++)
    {
        interests[i]=fmax(k,float((x*p[i])/(float)100));
        sum+=interests[i];
    }
    if(sum<=d)
        return "fee";
    else
        return "upfront";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int k;
        int x;
        int d;
        cin >> n >> k >> x >> d;
        vector<int> p(n);
        for(int p_i = 0; p_i < n; p_i++){
           cin >> p[p_i];
        }
        string result = feeOrUpfront(n, k, x, d, p);
        cout << result << endl;
    }
    return 0;
}
