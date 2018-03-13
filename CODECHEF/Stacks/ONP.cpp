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

        stack<char> ops;
        int i = 0;
        while(i < s.size())
        {
            if(isalpha(s[i]))
            {
                cout << s[i];
            }
            else if(s[i] == '(')
                ops.push(s[i]);
            else if(s[i] == ')')
            {
                while(ops.top() != '(')
                {
                    cout << ops.top();
                    ops.pop();
                }
                ops.pop();
            }
            else
            {
                ops.push(s[i]);
            }
            i++;
        }
        while(!ops.empty())
        {
            cout << ops.top();
            ops.pop();
        }
        cout << endl;
    }
    return 0;
}