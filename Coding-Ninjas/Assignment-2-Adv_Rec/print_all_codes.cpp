#include <string>
#include<iostream>
#include<map>
using namespace std;
map<string,char> keyMap;

void printAllPossibleCodes(string input,string output="") {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    char ch='a';
    for(int i=1;i<=26;i++,ch++)
        keyMap[to_string(i)]=ch;
  
    if(input=="")
    {
        cout<<output<<endl;
        return;
    }
    printAllPossibleCodes(input.substr(1),output+keyMap[string(1,input[0])]);
    if(input.size()>1 && stoi(input.substr(0,2))<=26)
        printAllPossibleCodes(input.substr(2),output+keyMap[input.substr(0,2)]);
}

int main()
{
    string input;
    cin>>input;
    printAllPossibleCodes(input);
}

