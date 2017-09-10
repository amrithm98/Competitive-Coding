#include <bits/stdc++.h>

using namespace std;

int charDiff(char a,char b)
{
    return abs(a-b);
}

string funnyString(string s){
    // Complete this function
    int len=s.size()-1;
    int flag=0;
    for(int i=0;i<len;i++)
    {
        int revIndex=len-i;
        int diff_fwd=charDiff(s[i],s[i+1]);
        int diff_rev=charDiff(s[revIndex],s[revIndex-1]);
        if(diff_fwd!=diff_rev)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        return "Not Funny";
    else    
        return "Funny";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        string result = funnyString(s);
        cout << result << endl;
    }
    return 0;
}
