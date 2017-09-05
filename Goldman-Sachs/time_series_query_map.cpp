#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

int main() 
{
    long long n;
    long long q;
    cin >> n >> q;
    vector<long long> t(n);
    map<long long,long long> time_price;
    for(long long t_i = 0; t_i < n; t_i++){
       cin >> t[t_i];
    }
    for(long long p_i = 0; p_i < n; p_i++){
        long long num;
        cin>>num;
        time_price[t[p_i]]=num;
    }
    for(long long a0 = 0; a0 < q; a0++)
    {
        int _type;
        long long v;
        cin >> _type >> v;
        if(_type==1)
        {
            long long val=-1;
             for(auto it:time_price)
            {
                if(it.second>=v)
                {
                    val=it.first;
                    break;
                }
            }
            cout<<val<<"\n";
        }
        else
        {
            long long max=-1;
            for(auto it:time_price)
            {
                if(it.first>=v)
                {
                    if(it.second>max)
                        max=it.second;
                }
            }
            cout<<max<<"\n";
        }
    }
    return 0;
}
