#include <bits/stdc++.h>
#include <map>
using namespace std;

string twoStrings(string s1, string s2){
    // Complete this function
    int len_s1=s1.size();
    int len_s2=s2.size();

    int i=0;

    map<char,int> charMap1,charMap2;
    
    for(i=0;i<len_s1;i++)
    {
        charMap1[s1[i]]++;
    }

    for(i=0;i<len_s2;i++)
    {
        charMap2[s2[i]]++;
    }

    int flag=0;

    for(auto it:charMap1)
    {
        if(charMap2.find(it.first)!=charMap2.end())
        {
            flag=1;
            break;
        }
    }   

    if(flag)
        return "YES";
    else
        return "NO";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        string result = twoStrings(s1, s2);
        cout << result << endl;
    }
    return 0;
}
