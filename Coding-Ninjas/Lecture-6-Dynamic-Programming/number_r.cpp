#include <bits/stdc++.h>
using namespace std;

int max_val(int *arr,int n)
{
    int max_val = INT8_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max_val)
            max_val = arr[i];
    }
    return max_val;
}

long kadanes(int *arr,int n,bool allNeg)
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
    while(n--)
    {
        string s;
        cin >> s;
        int len = s.size();
        int *score = new int[len];
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'R')
            {
                score[i] = -1;
                sum += 1;
            }
            else
            {
                score[i] = 1;
            }
        }
        //Only R's ...Then at least 1 R must be changed to 'K' to satisfy 1 move condition
        if(sum == len)
        {
            cout<<len-1<<endl;
            continue;
        }  
        cout<<sum+kadanes(score,len,false)<<endl;
    }
    return 0;
}
