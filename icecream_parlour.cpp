#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> cost,int beg,int end,int val)
{
    while(beg<=end)
    {   
        int mid=(beg+end)/2;
        if(cost[mid]==val)
        {
            cout<<"\nFound Val "<<cost[mid]<<"\t"<<mid<<"\n";
            return mid;
        }
        else if(cost[mid]<val)
        {
            beg=mid+1;
        }
        else if(cost[mid]>val)
        {
            end=mid-1;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) 
    {       
        int n,m;
        cin >> m >> n;
        vector<int> arr(n);
        int i=0,bsVal=0;
        for(i=0;i<n;i++)
            cin>>arr[i];
        int flag=0;
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && arr[i]+arr[j]==m)
                {
                    cout<<i+1<<" "<<j+1<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }

    }


}