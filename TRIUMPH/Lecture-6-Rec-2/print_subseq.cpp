#include <bits/stdc++.h>
using namespace std;


void subs(string in,string s = "")
{
    if(in.empty())
    {
        cout << s << endl;
        return;
    }
    subs(in.substr(1),s);
    subs(in.substr(1),s + in[0]);
}

int main()
{
    string s;
    cin >> s;
    subs(s);
    return 0;
}