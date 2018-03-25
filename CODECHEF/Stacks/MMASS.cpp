#include <bits/stdc++.h>
using namespace std;

int getMass(char ch)
{
    if(ch == 'H')
        return 1;
    if(ch == 'O')
        return 16;
    if(ch == 'C')
        return 12;
}

int main()
{
    string s;
    cin >> s;

    stack<int> mass;
    for(int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if(ch == '(')
            mass.push(-1);
        else if(ch == ')')
        {
            int m = 0;

            while(!mass.empty() && mass.top() !=-1)
            {
                m += (mass.top());
                mass.pop();
            }

            mass.pop();
            mass.push(m);
        }
        else if(isdigit(ch))
        {
            int top = mass.top();
            int m = top*(ch-'0');
            mass.pop();
            mass.push(m);
        }
        else if(isalpha(ch))
        {
            mass.push(getMass(ch));
        }
    }

    int m = 0;
    while(!mass.empty())
    {
        m += mass.top();
        mass.pop();
    }
    cout << m << endl;

    return 0;
}