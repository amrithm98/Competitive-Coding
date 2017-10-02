#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string a="p++";
    string b="++p";
    string c="--p";
    string d="p--";
    string e="p=0";
    int finalVal=0;
    for(int i=0;i<n;i++)
    {
        string input;
        cin>>input;
        if(input.compare(a)==0 || input.compare(b)==0)
            finalVal++;
        else if(input.compare(c)==0 || input.compare(d)==0)
            finalVal--;
        else if(input.compare(e)==0)
            finalVal=0;
        cout<<finalVal<<endl;
    }
    return 0;
}
