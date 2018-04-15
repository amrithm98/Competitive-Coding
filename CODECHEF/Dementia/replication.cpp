#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        LL n,k;
        cin >> n >> k;

        unordered_map<LL,LL> countMap;
        for(int i = 0; i < n; i++)
        {
            LL x;
            cin >> x;

            countMap[x]++;
        }

        LL sum = 0;

        for(auto it : countMap)
        {
            if(it.second == k)
            {
                sum += it.first;
            }
        }
        
        if(sum == 0)
        {
            cout << -1 << endl;
            continue;
        }
        else
            cout << sum << endl;
    }
    return 0;
}