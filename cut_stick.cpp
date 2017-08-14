#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int i,j,k;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    while(1)
    {
        int min=arr[0];
        int rem=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]!=0)
            {
                rem++;
            }
        }
        if(rem==0)
            break;
        cout<<rem<<"\n";
        for(i=1;i<n;i++)
        {
            if(arr[i]<min && arr[i]!=0)
            {
                min=arr[i];
            }
            if(min==0)
            {
                min=arr[i];
            }
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]!=0)
            {
                arr[i]-=min;
            }
        }
    }
    return 0;
}