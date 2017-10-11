#include <bits/stdc++.h>
#include <map>
using namespace std;

string gameOfThrones(string s)
{
    // Complete this function
    map<char,int> charMap;
    int len = s.size();
    int i = 0;

    for(;i<len;i++)
    {
        charMap[s[i]]++;
    }

    int count_odd=0,count_even=0;

    for(auto it:charMap)
    {
        if(it.second%2==0)
            count_even++;
        else    
            count_odd++;
    }

    if(count_odd==1 || count_odd==0)
        return "YES";
    
    else
        return "NO";

}

int main() {
    string s;
    cin >> s;
    string result = gameOfThrones(s);
    cout << result << endl;
    return 0;
}
