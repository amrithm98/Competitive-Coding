#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkPossible(vector<long long> arr,int n,long long mid,int k)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        count += arr[i]/mid;
    }
    // cout<<count<<endl;
    if(count >= k)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    for(int t0 = 0; t0 < t; t0++)
    {
        long long n,k;
        cin >> n >> k;

        vector<long long> arr(n);

        long long i,sum = 0;

        for(i = 0;i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        sort(arr.begin(),arr.end());

        long long beg = 1;
        long long end = sum/k;
        long long ans = -1;

        while(beg <= end)
        {
            long long mid=(beg+end)/2;
            if(checkPossible(arr,n,mid,k))
            {
                ans = mid; 
                beg = mid +1;
            }
            else
                end = mid -1;
        }

        cout<<ans<<endl;
    }
}