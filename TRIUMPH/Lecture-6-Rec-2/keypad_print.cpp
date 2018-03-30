#include <bits/stdc++.h>
using namespace std;

unordered_map<int,string> keypad;

void keypadCode(int n,string s = "")
{
    if(n == 0)
    {
        cout << s << endl;
        return;
    }

    int quo = n / 10;
    int rem = n % 10;

    for(int i = 0; i < keypad[rem].size(); i++)
    {
        keypadCode(quo,keypad[rem][i]+s);
    }
}

int main()
{
    keypad[2] = "abc";
    keypad[3] = "def";
    keypad[4] = "ghi";
    keypad[5] = "jkl";
    keypad[6] = "mno";
    keypad[7] = "pqrs";
    keypad[8] = "tuv";
    keypad[9] = "wxyz";
    
    int n;
    cin >> n;

    keypadCode(n);
    return 0;
}