#include <bits/stdc++.h>
using namespace std;

long max_val(long *arr,int n)
{
    long max_val = INT8_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max_val)
            max_val = arr[i];
    }
    return max_val;
}

long kadanes(long *arr,int n,bool allNeg)
{
    if(allNeg)
    {
        return max_val(arr,n);
    }
    long long curr_max = 0,best_max = 0;
    for(int i = 0; i < n; i++)
    {
        curr_max += arr[i];
        if(best_max < curr_max)
        {
            best_max = curr_max;
        }
        if(curr_max < 0)
            curr_max = 0;
    }
    return best_max;
}
int main()
{
    int n;
    cin >> n;
    long *arr = new long[n];
    bool allNeg = true;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] > 0)
            allNeg = false;
    }
    cout<<kadanes(arr,n,allNeg)<<endl;
}