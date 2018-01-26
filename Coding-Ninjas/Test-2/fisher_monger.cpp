#include <iostream>
#include <climits>
using namespace std;

int dp[101][1001];
int times[101][1001],toll[101][1001];

void DFS(int start,int time,int paid,int n,int t)
{
    dp[start][time] = min(dp[start][time] , paid);

    for(int i = 0; i < n; i++ )
    {
        if(i == start || dp[start][time] + times[start][i] > t)
        {
            continue;
        }

        if(dp[i][time + times[start][i]] > dp[start][time]+toll[start][i])
        {
            DFS(i,time + times[start][i],paid + toll[start][i],n,t);
        }
    }
}

int main() 
{
	int n, t;
	cin >> n >> t;


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> times[i][j];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> toll[i][j];
    }  

    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j <= 1000; j++)
            dp[i][j] = INT_MAX;
    }  
        
    DFS(0,0,0,n,t);

    int result = dp[n-1][0];

    for(int i = 1; i <= t; i++)
    {
        result = min(result,dp[n-1][i]);
    }

    cout<<result<<endl;

    return 0;
}