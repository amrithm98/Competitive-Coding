#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        unordered_map<char,int> cmap;
        for(int i = 0; i < s.size(); i++)
            cmap[s[i]]++;
        
        vector<int> nums;
        for(auto it : cmap)
            nums.push_back(it.second);

        if(nums.size()  < 3)
        {
            cout << "Dynamic\n";
            continue;
        }

        sort(nums.begin(),nums.end());

        bool flag1 = true;

        for(int i = 2; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1]+nums[i-2])
            {
                flag1 = false;
                break;
            }
        }

        bool flag2 = true;
        swap(nums[0],nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1]+nums[i-2])
            {
                flag2 = false;
                break;
            }
        }

        if(flag1 || flag2)
            cout << "Dynamic" << endl;
        else
            cout << "Not" << endl;
    }

    return 0;
}