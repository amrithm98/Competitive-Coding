#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        // your code goes here
        string str="hackerrank";
        if(s.size()<str.size())
        {
            cout<<"NO"<<"\n";
        }
        else
        {
            int j=0;
            for(int i=0;i<s.size();i++)
            {
                if(j<str.size() && s[i]==str[j])
                {
                    j++;
                }
            }
            if(j==10)
                cout<<"YES"<<"\n";
            else    
                cout<<"NO"<<"\n";
        }
    }
    return 0;
}
