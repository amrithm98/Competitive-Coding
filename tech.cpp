#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        unordered_map<char,int> map;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='I')
                map['I']+=1;
            else if(s[j]=='E')
                map['E']+=1;
        }
        int maxE=map['E']/3;
        int maxI=map['I'];
        cout<<min(maxE,maxI)<<"\n";
    }
}