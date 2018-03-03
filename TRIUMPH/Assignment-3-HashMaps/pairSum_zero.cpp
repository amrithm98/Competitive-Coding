#include <bits/stdc++.h>
using namespace std;

void PairSum(int *input, int n) 
{	 
    unordered_map<int,int> countMap;
    for(int i = 0; i < n; i++)
    {
        countMap[input[i]]++;
    }

    for(auto it1 = countMap.begin(); it1 != countMap.end(); it1++)
    {
        auto it = *it1;
        if(countMap.find(-1*it.first) != countMap.end())
        {
            int count = (it.second)*(countMap[-1*it.first]);
            for(int i = 0; i < count; i++)
            {
                cout << min(it.first,-1*it.first) << " " << max(it.first,-1*it.first) << endl;
            }
            countMap.erase(it.first);
            countMap.erase(-1*it.first);
          	if(countMap.size() != 0)
            	it1 = countMap.begin();
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    PairSum(arr,n);
    return 0;
}

