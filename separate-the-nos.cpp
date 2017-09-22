#include <bits/stdc++.h>

using namespace std;


int charDiff(char a,char b)
{
    return (a-b);
}
string beatiful(string s)
{
    int len=s.size();
    for(int i=0;i<len-1;i++)
    {
        if(s[i]!=0 && charDiff(s[i],s[i+1])==1)
            cout<<s[i]<<"\n";
    }
    return s;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        // your code goes here
        cout<<beatiful(s)<<endl;
    }
    return 0;
}
