#include <bits/stdc++.h>

using namespace std;

int theLoveLetterMystery(string s){
    // Complete this function
    int len=s.size();
    int count=0;
    if(len%2==0)
    {
        for(int i=len/2,k=1;i<len;i++,k++)
        {
            count+=abs(s[i]-s[len/2-k]);
        }
    }
    else
    {
        for(int i=len/2+1,k=1;i<len;i++,k++)
        {
            count+=abs(s[i]-s[len/2-k]);
        }
    }
    return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = theLoveLetterMystery(s);
        cout << result << endl;
    }
    return 0;
}
