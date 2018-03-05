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

        unordered_map<char,int> cm1,cm2;
        int len = s.size();
        for(int i = 0; i < len/2; i++)
        {
            cm1[s[i]]++;
        }
        for(int i = (len+1)/2; i < len; i++)
        {
            cm2[s[i]]++;
        }

        int flag = true;
        for(auto it : cm1)
        {
            if(cm2[it.first] != it.second)
            {
                flag = false;
                break;
            }
        }

        for(auto it : cm2)
        {
            if(cm1[it.first] != it.second)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;  
    }
    return 0;
}