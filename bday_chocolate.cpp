#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    int j,k=1,t=m,sum=0,count=0;
    for(int i=0;i<n;i++){
        sum=s[i];
        for(j=k;j<t;j++){
            sum+=s[j];
        }
        if(sum==d){
            count++;
        }
        k++;
        t++;
    }
return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}
