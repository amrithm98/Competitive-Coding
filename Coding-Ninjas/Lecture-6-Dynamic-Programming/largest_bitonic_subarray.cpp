#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubarray(int *input, int n) {
    
/* Don't write main().
    * the input is already passed as function argument.
    * Taking input and printing output is handled automatically.
    */
    vector<int> tail;
    vector<int> inc(n,0),dec(n,0);

    for(int i = 0; i < n; i++)
    {
        auto len = lower_bound(tail.begin(),tail.end(),input[i]);
        if(len == tail.end())
        {
            tail.push_back(input[i]);
            inc[i] = tail.size();
        }
        else
        {
            tail[len-tail.begin()] = input[i];
            inc[i] = len-tail.begin()+1;
        }
    }

    tail.clear();

    for(int i = n-1; i  >= 0; i--)
    {
        auto len = lower_bound(tail.begin(),tail.end(),input[i]);
        if(len == tail.end())
        {
            tail.push_back(input[i]);
            dec[i] = tail.size();
        }
        else
        {
            tail[len-tail.begin()] = input[i];
            dec[i] = len-tail.begin()+1;
        }
    }

    int curr_max = 0,curr = 0;

    for(int i = 0; i < n; i++)
    {
        curr = inc[i] + dec[i];
        if(curr > curr_max)
            curr_max = curr;
    }


    // for(int i = 0; i < n; i++)
    //     cout<<dec[i]<<" ";
    // cout<<"\n";
    // for(int i = 0; i < n; i++)
    //     cout<<inc[i]<<" ";

    return curr_max - 1;

/***
 * 16 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
  
 **/
}

int main()
{
    int n;
    cin >> n;
    int * in = new int[n];
    for(int i = 0; i < n; i++)
        cin >> in[i];
    cout<<longestBitonicSubarray(in,n)<<endl;
    return 0;
}
