#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;

char* uniqueChar(char *str){
    // Write your code here
    unordered_map<char,int> unique;
    char *res=new char[50000];
    int k=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(unique[str[i]]==0)
        {
            res[k]=str[i];
            k++;
            unique[str[i]]++;
        }
    }
    return res;
}

int main()
{
   char str[50000];
   cin>>str;
   char *res;
   res=uniqueChar(str);
   for(int i=0;i<strlen(res);i++)
        cout<<res[i];

}
