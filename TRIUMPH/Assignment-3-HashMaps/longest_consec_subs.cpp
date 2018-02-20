#include <bits/stdc++.h>
using namespace std;

vector<int> longestSubsequence(int *arr, int n)
{
	unordered_set<int> hashMap;
    vector<int> ans;

    int start = -1;
    int count = -1;

    for(int i = 0; i < n; i++)
        hashMap.insert(arr[i]);

    for(int i = 0; i < n; i++)
    {
        int num = arr[i];
        if(hashMap.find(num-1) == hashMap.end())
        {
            while(hashMap.find(num) != hashMap.end())
                num++;
            
            if(count < num - arr[i])
            {
                count = num - arr[i];
                start = arr[i];
            }
        }
    }

    for(int i = start; i < start+count; i++)
        ans.push_back(i);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = longestSubsequence(arr,n);

    for(auto it : ans)
        cout << it << " ";

    return 0;
}