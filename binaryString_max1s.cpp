#include<iostream>
#include<string>
using namespace std;
int maxLengthOnes(string s)
{
    int count=0,result=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            count++;
            result=max(count,result);
        }
        else
            count=0;
    }
    return result;
}
int main()
{
    string s;
    cin>>s;
    cout<<"\n"<<maxLengthOnes(s);
}