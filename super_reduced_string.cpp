#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

string super_reduced_string(string s)
{
    // Complete this function
    for(int i=1;i<s.size();i++)
    {
        cout<<s.size()<<"\n";
        if(s[i]==s[i-1])
        {
            s.erase(i-1,i+1);
            i=0;
        }
    }

    if(s.size()==0)
        return "Empty String\n";
    else
        return s;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
