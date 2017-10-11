#include<iostream>
#include<map>
#include<string>
using namespace std;
map<int,string> keyMap;
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    keyMap[0]="";
    keyMap[2]="abc";
    keyMap[3]="def";
    keyMap[4]="ghi";
    keyMap[5]="jkl";
    keyMap[6]="mno";
    keyMap[7]="pqrs";
    keyMap[8]="tuv";
    keyMap[9]="wxyz";

    if(num==0)
    {
        output[0]="";
        return 1;
    }
    else
    {
        int quo=num/10;
        int rem=num%10;
        int smallOutput=keypad(quo,output);   
        for(int j=0;j<smallOutput;j++)
        {
            string temp=output[j];
            for(int i=0;i<keyMap[rem].size();i++)
            {
                output[i*smallOutput+j]=temp+keyMap[rem][i];
            }
        }
        return smallOutput*keyMap[rem].size();
    }
}

int main()
{
    int n;
    cin>>n;
    string *output=new string[1000];
    int len=keypad(n,output);
    for(int i=0;i<len;i++)
        cout<<output[i]<<endl;
    return 0;
}