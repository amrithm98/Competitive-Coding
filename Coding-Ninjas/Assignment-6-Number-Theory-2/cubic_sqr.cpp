#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--)
    {
        long long a,mod;
        string b;
        cin >> a >> b >> mod;
        int len = b.size();
        long long ans = 1;
        while(len--)
        {
            int lsb = b[len] - '0';
            if(lsb != 0)
            {
                ans = (ans * a)%mod;
            }
            if(lsb == 2)
            {
                ans = (ans * a)%mod;
            }
            a = (((a * a)%mod)*a)%mod;
        }
        cout<<ans<<endl;
    }   
}