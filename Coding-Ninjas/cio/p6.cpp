#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c){
    // Complete this function
    vector<long> table(n+1);
    table[0]=1;
    for(long i=0;i<c.size();i++)
    {
        for(long j=c[i];j<=n;j++)
        {
            table[j]+=table[j-c[i]];
            // cout<<"\n"<<j<<"\t"<<table[j];
        }
    }
    return table[n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout<<ways<<endl;
    return 0;
}
