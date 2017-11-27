#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> brands(n);
    map<int,int> brandCount;
    map<int,vector<long>> brandPriceList;

    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        brandCount[b]++;
        brands[i] = b;
    }
    
    for(int i = 0; i < n; i++)
    {
        long p;
        cin >> p;
        brandPriceList[brands[i]].push_back(p);
    }

    // for(auto it:brandCount)
    //     cout<<it.first<<" "<<it.second<<endl;
    // for(auto it:brandPriceList)
    // {
    //     cout<<it.first<<endl;
    //     for(int i = 0; i < it.second.size(); i++)
    //         cout<<it.second[i]<< " ";
    //     cout<<endl;
    // }

    int q;
    cin >> q;
    while(q--)
    {
        int d;
        cin >> d;
        vector<int> opts;
        for(int i = 0; i < d; i++)
        {
            int b;
            cin >> b;
            opts.push_back(b);
        }
        int k;
        cin >> k;
        vector<int> concat_list;
        for(int i = 0; i < d; i++)
        {
            // cout<<opts[i]<<endl<<endl;
            if(!brandPriceList[opts[i]].empty())
                for(int j = 0; j < brandPriceList[opts[i]].size() ; j++)
                    concat_list.push_back(brandPriceList[opts[i]][j]);
        }

        if(!concat_list.empty())
        {
            // cout<<"K: "<<k<<endl;
            if(k <= concat_list.size())
            {
                sort(concat_list.begin(),concat_list.end());
                cout<<concat_list[k-1]<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
           
        }
        else
        {
            cout<<-1<<endl;
        }
        
    }
    return 0;
}
