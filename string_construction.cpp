#include <bits/stdc++.h>
#include <map>
using namespace std;

int stringConstruction(string s) {
    // Complete this function
    int len=s.size();
    int i=0;
    
    map<char,int> visitedCharMap;

    int cost=0;

    for(int i=0;i<len;i++)
    {
        if(visitedCharMap.find(s[i])==visitedCharMap.end())
        {
            visitedCharMap[s[i]]++;
            cost++;
        }
    }

    return cost;
}

int main() 
{
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = stringConstruction(s);
        cout << result << endl;
    }
    return 0;
}
