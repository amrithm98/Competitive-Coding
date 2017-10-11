#include<iostream>
using namespace std;

int subsequence(string s,string output[])
{
    if(s.empty())
    {
        output[0]="";
        return 1;
    }
    else
    {
        string smallString=s.substr(1);
        int smallOutput=subsequence(smallString,output);
        for(int i=0;i<smallOutput;i++)
        {
            output[smallOutput+i]=s[0]+output[i];
        }
        return 2*smallOutput;
    }
}
int main()
{
    string s;
    cin>>s;
    string *output=new string[1000];
    int length=subsequence(s,output);
    for(int i=0;i<length;i++)
        cout<<output[i]<<"\n";
}