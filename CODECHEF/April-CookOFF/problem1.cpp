#include <bits/stdc++.h>
using namespace std;

string winner(vector<string> stk,int start)
{
    int zero = 0,one = 0;
    for(int i = 0; i < stk.size(); i++)
    {
        if(stk[i][0] == '0')
        {
            for(auto it : stk[i])
            {
                if(it == '0')
                    zero++;
            }
        }
        else if(stk[i][0] == '1')
        {
            for(auto it : stk[i])
            {
                if(it == '1')
                    one++;
            }
        }
    }
    if(zero > one)
        return "Dee";
    else if(one > zero)
        return "Dum";
    else
    {
        return (start == 0)?"Dum":"Dee";
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int start = -1;
        if(s == "Dee")
            start = 0;
        else 
            start = 1;

        vector<string> stk;

        for(int i = 0; i < n; i++)
        {
            string k;
            cin >> k;

            stk.push_back(k);
        }

        cout << winner(stk,start) << endl;
    }

    return 0;
}