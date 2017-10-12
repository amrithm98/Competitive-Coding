#include <string>
#include<iostream>
#include<map>
using namespace std;
map<string,char> keyMap;
int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    char ch='a';
    for(int i=1;i<=26;i++,ch++)
        keyMap[to_string(i)]=ch;
    
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    int smallOutput1=getCodes(input.substr(1),output);
    int smallOutput2=getCodes(input.substr(2),output);
    int smallOutput=smallOutput1+smallOutput2;

    int i,j;
    for(i=0;i<smallOutput1;i++)
    {
        output[smallOutput1+i]=keyMap[to_string(input[0])]+output[i];
    }
    for(j=smallOutput1;j<smallOutput;j++)
    {
        output[smallOutput+j]=keyMap[input.substr(0,2)]+output[j];
    }
    return smallOutput;
    
}

int main()
{
    string input;
    cin>>input;

    string *output=new string[1000];
    int len=getCodes(input,output);

    for(int i=0;i<len;i++)
    cout<<output[i]<<endl;

}
