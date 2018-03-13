#include<bits/stdc++.h>
using namespace std;
#define LL long long int

struct Job
{
    int start;
    int end;
    int profit;
};

bool compare(Job a,Job b)
{
    return a.end < b.end;
}

int maxProfit(Job *jobs, int n, int *dp)
{
    dp[0] = jobs[0].profit;

    for(int i = 1; i < n; i++)
    {
        int incl = jobs[i].profit;
        int latestNonConflict = -1;

        for(int j = i-1; j >= 0; j--)
        {
            if(jobs[j].end <= jobs[i].start)
            {
                latestNonConflict = j;
                break;
            }
        }

        if(latestNonConflict != -1)
        {
            incl += dp[latestNonConflict];
        }
        dp[i] = max(incl,dp[i-1]);
    }
    
    return dp[n-1];
}

int main()
{
    int n;
    cin >> n;

    Job *jobs = new Job[n];
    for(int i = 0; i < n; i++)
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;

    sort(jobs,jobs+n,compare);

    int *dp = new int[n+1];
    
    cout << maxProfit(jobs,n,dp) << endl;

    return 0;
}