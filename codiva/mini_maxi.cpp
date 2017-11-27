#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,q;
    cin >> n >> q;
    vector<int> arr(n,0);
    while(q--)
    {
        // cout<<"\nARRAY: \n";
        // for(int i = 0; i < n; i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        int type;
        cin >> type;
        if(type == 1)
        {
            int l,r,val;
            cin >> l >> r >>val;
            l--,r--;
            for(int i = l; i <= r; i++)
                arr[i] = arr[i]^val;
        }
        else if(type == 2)
        {
            int l,r,i,j;
            cin >> l>> r;
            l--,r--;
            int count_ones = 0;
            for(i = l; i <= r; i++)
            {
                if(arr[i] == 1)
                {
                    count_ones ++;
                    break;
                }
            }
            // cout<<"\nType 2 : i :"<<i<<endl;
            int count = INT8_MAX;
            for(j = i+1; j <= r; j++)
            {   
                // cout<<arr[j]<<endl;
                if(arr[j] == 1)
                {
                    count_ones++;
                    count = min(count,j-i);
                    i = j;
                }
            }
            // cout<<"\nType 2 : Count :"<<count<<endl;
            if(count_ones < 2)
                cout<<-1<<endl;
            else
                cout<<count<<endl;
        }
        else if(type == 3)
        {
            int l,r,i,j;
            cin >> l>> r;
            l--,r--;
            int count_ones = 0;
            for(i = l; i <= r; i++)
            {
                if(arr[i] == 1)
                {
                    count_ones++;
                    break;
                }
            }
            for(j = r; j >= i; j--)
            {   
                if(arr[j] == 1)
                {
                    count_ones++;
                    break;
                }
            }
            if(count_ones < 2)
                cout<<-1<<endl;
            else
                cout<<j-i<<endl;
        }
    } 
    return 0;
}
