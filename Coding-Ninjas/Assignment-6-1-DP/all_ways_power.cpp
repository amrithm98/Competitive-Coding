#include <bits/stdc++.h>
using namespace std;

int allWays(int x, int n,int m = 1) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    int val = (x - pow(m,n));
    
    if(val == 0)
    {
        return 1;
    }

    if(val < 0)
        return 0;

    
    return allWays(val,n,m+1) + allWays(x,n,m+1);
    // int ans = 0;

    // for(int i = m; i <= x; i++)
    // {
    //     ans += allWays(x-pow(i,n), n,i+1);
    // }
    // return ans;
}

int main()
{
    int a,b;
    cin >> a >> b;

    cout << allWays(a,b) << endl;

    return 0;
}