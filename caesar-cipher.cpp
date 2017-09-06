#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    int charCase=0; //0-Lower
    for(int i=0;i<s.size();i++)
    {
        char c=(char)s[i];
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            if((s[i]>='a' && s[i]<='z'))
            {
                charCase=0;
            }
            else if((s[i]>='A' && s[i]<='Z'))
            {
                charCase=1;
            }
            for(int m=0;m<k;m++)
            {
                c++;
                if(charCase==1)
                {
                    if(c>90)
                        c=65;
                }
                else
                {
                    if(c>122)
                        c=97;
                }
            }
        }
        cout<<c;
    
    }
    return 0;
}
