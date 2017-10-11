#include<iostream>
#include<map>
using namespace std;
map<int,string> keyMap;
void printKeypad(int n,string output="")
{
    keyMap[0]="";
    keyMap[2]="abc";
    keyMap[3]="def";
    keyMap[4]="ghi";
    keyMap[5]="jkl";
    keyMap[6]="mno";
    keyMap[7]="pqrs";
    keyMap[8]="tuv";
    keyMap[9]="wxyz";

    if(n==0)
    {
        cout<<output<<endl;
        return;
    }
    else
    {
        int quo=n/10;
        int rem=n%10;
        for(int i=0;i<keyMap[rem].size();i++)
        {
            printKeypad(quo,keyMap[rem][i]+output);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    printKeypad(n);
}