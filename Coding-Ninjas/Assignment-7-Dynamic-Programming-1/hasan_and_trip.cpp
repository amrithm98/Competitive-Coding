#include <bits/stdc++.h>
using namespace std;

double dp[3030];
double x[3030],y[3030],f[3030];

double calc_dist(int a,int b)
{
    double x_diff = x[a] - x[b];
    double y_diff = y[a] - y[b];
    double ans = sqrt( (x_diff*x_diff) + (y_diff*y_diff) );
    return ans;

}

int main()
{
    int n;
    cin >> n;

    
    for(int i = 0; i < n; i++)
    {       
        cin >> x[i] >> y[i] >> f[i];
    }

    for(int i = 0; i < n; i++)
        dp[i] = -1e9;
    
    dp[0] = 0;

    for(int i = 0; i < n; i++)
    {

        dp[i] += f[i];

        for(int j = i+1; j < n; j++)
        {
            double dist = calc_dist(i,j);
            dp[j] = max(dp[j],dp[i]-dist);
        }

    }

    cout<<fixed;
    cout.precision(6);
    cout<<dp[n-1]<<endl;

    return 0;
}
