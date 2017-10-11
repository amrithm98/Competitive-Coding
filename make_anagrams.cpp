#include <bits/stdc++.h>
#include <map>
using namespace std;

int makingAnagrams(string s1, string s2){
    // Complete this function
    map<char,int> charMap1,charMap2;
    int len_s1=s1.size(),len_s2=s2.size();

    for(int i=0;i<len_s1;i++)
        charMap1[s1[i]]++;

    for(int i=0;i<len_s2;i++)
        charMap2[s2[i]]++;

    int count=0;
    for(auto it:charMap1)
    {
        if(charMap2.find(it.first)==charMap2.end())
        {
            count+=it.second;
        }
        else
        {
            count+=abs(it.second-charMap2[it.first]);
        }
    }
    for(auto it:charMap2)
    {
        if(charMap1.find(it.first)==charMap1.end())
        {
            count+=it.second;
        }
        // Not Needed Twice
        // else
        // {
        //     count+=abs(it.second-charMap2[it.first]);
        // }
    }
    return count;
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = makingAnagrams(s1, s2);
    cout << result << endl;
    return 0;
}
