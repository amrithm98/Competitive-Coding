#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;


char nonRepeatingCharacter_wrong(string str){
  
  //Write your code here
  unordered_map<char,int> mapVals;
  char non_repeat='*';
  for(int i=str.size()-1;i>=0;i--)
  {
      mapVals[str[i]]++;
      if(mapVals[str[i]]<=1)
        non_repeat=str[i];
  }
  if(mapVals[non_repeat]>1)
    non_repeat='*';
  if(non_repeat!='*')
    return non_repeat;
  else 
    return str[0];


}

char nonRepeatingCharacter_accepted(string str){
  
  //Write your code here
  unordered_map<char,int> mapVals;
  int len=str.size();
  char non_repeat='*';
  for(int i=0;i<len;i++)
  {
      mapVals[str[i]]++;
  }
  for(int i=0;i<len;i++)
  {
      if(mapVals[str[i]]==1)
      {
        non_repeat=str[i];
        break;
      }
  }
  if(non_repeat=='*')
    return str[0];
  else  
    return non_repeat;
}

int main()
{
    string s;
    cin>>s;
    cout<<"\nOUTPUT:";
    cout<<nonRepeatingCharacter_accepted(s);
}
