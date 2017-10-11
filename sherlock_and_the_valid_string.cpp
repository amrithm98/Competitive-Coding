#include <bits/stdc++.h>
#include <map>
#include <set>
using namespace std;

string isValid(string s){
    // Complete this function
    map<char,int> charMap;
    int len=s.size();

    int i;
    for(i=0;i<len;i++)
    {
        charMap[s[i]]++;
    }

    int flag=0;

    
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
