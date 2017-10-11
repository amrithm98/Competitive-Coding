#include <bits/stdc++.h>
#include <map>
using namespace std;

int anagram(string s)
{
    // Complete this function
    int len=s.size();

    if(len%2!=0)
        return -1;

    string s1=s.substr(0,len/2);
    string s2=s.substr(len/2,len/2);
    map<char,int> charMap;

    for(int i=0;i<len/2;i++)
    {
        charMap[s1[i]]++;
        charMap[s2[i]]--;
    }

    int count=0;

    for(auto it:charMap)
        count+=abs(it.second);
        
    return count/2;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = anagram(s);
        cout << result << endl;
    }
    return 0;
}
