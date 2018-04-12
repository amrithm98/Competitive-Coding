#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> cost(n);
    vector<int> type(n);

    for(int i = 0; i < n; i++)
        cin >> cost[i];

    for(int i = 0; i < n; i++)
        cin >> type[i];

    int min3 = INT_MAX;
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for(int i = 0; i < n; i++)
    {

        if(type[i] == 3)
            min3 = min(min3,cost[i]);

        else if(type[i] == 2)
            min2 = min(min2,cost[i]);
        
        else if(type[i] == 1)
            min1 = min(min1,cost[i]);

    }
    if(min1 == INT_MAX || min2 == INT_MAX)
        cout << min3 << endl;
    else
        cout << min(min1+min2,min3) << endl;

    return 0;
}
