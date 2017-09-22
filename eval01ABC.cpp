#include<iostream>
#include<string>
using namespace std;

bool evalBoolExp(string s)
{
    for(int i=0;i<s.size();i+=2)
    {
        if(s[i+1]=='A')
            if(s[i]=='0' && s[i+2]=='0')
                s[i+2]='0';
            else   
                s[i+2]='1';
        
        else if(s[i+1]=='B')
            if(s[i]=='0' || s[i+2]=='0')
                s[i+2]='0';
            else   
                s[i+2]='1';

        else if(s[i+1]=='C')
            if(s[i]==s[i+2])
                s[i+2]='0';
            else   
                s[i+2]='1';
            
    }
    return s[s.size()-1]-'0';
}
int main()
{
    string s;
    cin>>s;
}