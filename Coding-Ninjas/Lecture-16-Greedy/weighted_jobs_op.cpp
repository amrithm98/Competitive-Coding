#include <bits/stdc++.h>
using namespace std;

#define LL long long int

struct Job
{
    int start;
    int end;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.end < b.end;
}

int binSearch(Job *arr,int k)
{
    int low = 0;
    int high = k-1;

    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid].end <= arr[k].start)
        {
            if(arr[mid+1].end <= arr[k].start)
                low = mid+1;
            else    
                return mid;
        }
        else
            high = mid-1;
    }
    return -1;
}

int maxWeight(Job *arr, int n)
{
    int *dp = new int[n+1];
    dp[0] = arr[0].profit;

    for(int i = 1; i < n; i++)
    {
        int incl = arr[i].profit;
        int conflictIndex = binSearch(arr,i);
        if(conflictIndex != -1)
            incl += dp[conflictIndex];
        dp[i] = max(incl,dp[i-1]);
    }
    return dp[n-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    Job *arr = new Job[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].end >> arr[i].profit;

    sort(arr,arr+n,compare);

    cout << maxWeight(arr,n) << endl;
    return 0;
}