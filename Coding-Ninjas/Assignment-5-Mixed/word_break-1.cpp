#include <bits/stdc++.h>
#include <map>
using namespace std;
map<string,int> dict;

void wordbreak(string s,int n,string output)
{
    for(int i = 1; i <= n ; i++)
    {
        string prefix = s.substr(0,i);
        if(dict.find(prefix)!=dict.end())
        {
            if(i == n)
            {
                output += prefix;
                cout<<output<<endl;
                return;
            }
            wordbreak(s.substr(i,n-i),n-i,output + prefix + " ");
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n ; i++)
    {
        string a;
        cin >> a;
        dict[a]++;
    }

    string s;
    cin >> s;
    wordbreak(s,s.size(),"");
    
    return 0;
}
