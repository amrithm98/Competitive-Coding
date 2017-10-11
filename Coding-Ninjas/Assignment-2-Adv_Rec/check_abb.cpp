#include<iostream>
using namespace std;

bool checkAB(char input[],char prev='\0') {
	// Write your code here
    if(input[0]=='\0')
        return true;
    else if(input[0]=='b' && prev=='\0')
        return false;
    else if(input[0]=='b' && prev=='b' && input[1]=='b')
        return false;
    else if(input[0]=='b' && prev!='b' && input[1]=='\0')
        return false;
    else if(input[0]=='b' && prev=='a' && input[1]!='b')
        return false;
    else
        return checkAB(input+1,input[0]);
    
}

int main()
{
    char input[100];
    scanf("%s",input);
    cout<<checkAB(input)<<endl;
}