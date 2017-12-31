#include<bits/stdc++.h>
using namespace std;

string choice(vector<string> words, int m)
{
    map<char,int> charMap1;
    int val = 0;
    for(int i = 0; i < words.size() - 1; i++)
    {
        for(int j = 0; j < words[i].size(); j++)
        {
            charMap1[words[i][j]]++;
        }
        int flag = 0;
        for(int j = 0; j < words[i+1].size(); j++)
        {
            if(charMap1[words[i+1][j]] > 0)
            {
                flag = 1;
                break;
            }
        }
        
        charMap1.clear();

        if(!flag)
            val++;
    }
    if(val > m)
        return "Very poor choice of words";
    else    
        return "Welcome to a world without rules";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<string> words(n);
        for(int i = 0; i < n; i++)
        {
            cin >> words[i];
        }
        cout<<choice(words,m)<<endl;
    }
}