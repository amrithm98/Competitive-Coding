#include <bits/stdc++.h>

using namespace std;

bool checkPalin(string s,int start,int end)
{
    bool res=true;
    int k=end;
    for(int i=start;i<k;i++,k--)
    {
        if(s[i]!=s[k])
        {
            return false;
        }
    }
    return true;
}
int palindromeIndex(string s){
    // Complete this function
    bool res=true;
    int k=s.size()-1;
    for(int i=0;i<k;i++,k--)
    {
        if(s[i]!=s[k])
        {
            if(checkPalin(s,i+1,k))
            {
                return i;
            }
            else
                return k;
        }
    }
    return -1;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}
