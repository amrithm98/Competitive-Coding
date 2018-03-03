#include <bits/stdc++.h>
using namespace std;

int makeAnagram(char str1[], char str2[])
{
    map<char,int> cnt1,cnt2;

    for(int i = 0; str1[i] != '\0'; i++)
    {
        cnt1[str1[i]]++;
    }
    for(int i = 0; str2[i] != '\0'; i++)
    {
        cnt2[str2[i]]++;
    }

    int diff = 0;

    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        diff += abs(cnt1[ch] - cnt2[ch]);
    }
    return diff;
}

int main()
{
    char str1[100],str2[100];
    cin >> str1;
    cin >> str2;
    cout << makeAnagram(str1,str2);
    return 0;
}
