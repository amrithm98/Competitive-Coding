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

        stack<int> ops;
        int count = 0;

        if(s[0] == '>')
        {
            cout << 0 << endl;
            continue;
        }

        int i = 0;
        while( i < s.size())
        {
            if(s[i] == '<')
                ops.push(i);

            else
            {
                if(!ops.empty() && s[ops.top()] == '<')
                {
                    ops.pop();
                    count++;
                }
                else
                {
                    break;
                }
            }
            i++;
        }
       cout << (ops.empty()?0:ops.top()) << endl;
    }
    return 0;
}