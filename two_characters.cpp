#include <bits/stdc++.h>
#include<map>

using namespace std;

int maxLen(string s){
    // Complete this function
    map<char,int> charMap;
    map<char,int> repeated;
    int i;
    for(i=0;i<s.size();i++)
        charMap[s[i]]++;
    for(i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
            repeated[s[i]]++;
    }
    string p="";
    for(auto it:repeated)
    {
        for(i=0;i<s.size();i++)
            if(s[i]!=it.first)
                p+=s[i];
    }
    int min=INT8_MAX;
    char min_char;
    if(charMap.size()>2)
    {
        charMap.clear();
        
        for(i=0;i<p.size();i++)
        {
            charMap[p[i]]++;
            if(charMap[p[i]]<=min)
            {
                min=charMap[p[i]];
                min_char=p[i];
            }
        }
        string q="";
        for(char a : p)
        {
            if(a!=min_char)
                q+=a;
            
        }
        return q.size();
    }
    else 
        return p.size();
    
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = maxLen(s);
    cout << result << endl;
    return 0;
}
