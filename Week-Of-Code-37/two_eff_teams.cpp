#include <bits/stdc++.h>
using namespace std;

long long maximumEfficiency(int n, int m)
{
    vector<long long> groups;
    vector<long long> prod;

    long long maxProd = 0;

    vector<pair<unordered_set<int>,long long>> gp;

    for(int i = 0; i < m; i++)
    {
        int s;
        long long val;
        cin >> s >> val;

        unordered_set<int> mems;
        long long mask = 0;

        for(int j = 0; j < s; j++)
        {
            int x;
            cin >> x;
            mems.insert(x);
            mask |= (1 << (x-1));
        }

        gp.push_back(make_pair(mems,val));
        prod.push_back(val);
        groups.push_back(mask);
        maxProd += val;
    }

    long long best = 0;
    long long best_mask = 0;

    for(long long mask = 1; mask < (1LL << n-1); mask++)
    {
        long long productivity = 0;
        for(int i = 0; i < m; i++)
        {
            long long g = groups[i];
            if( ((mask & g) == 0) || ((mask & g) == g))
            {
                productivity += prod[i];
            }
        }

        if(productivity > best)
        {
            best = productivity;
            best_mask = mask;
        }

        if(best == maxProd)
            break;
        //If the efficiency won't improve further then also Nirthi PO
        //TODO
    }
    // cout << "\nBest Group 1 : " << bitset<64>(best_mask) << endl;
    return best;
}

int main()
{
    int n,m;
    cin >> n >> m;

    cout << maximumEfficiency(n,m) << endl;
    return 0;

}

/*

40 5
5 10
1 2 3 4 5
4 70
34 37 27 4
3 20
6 7 5
4 12
11 12 13 15
5 6
20 21 22 23 15

*/