#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main()
{
    string s;
    getline(cin,s);
    s.erase(remove_if(s.begin(), s.end(),::isspace ),s.end());
    int len=s.size();
    int low=floor(sqrt(len));
    int high=ceil(sqrt(len));
    if(low*high<=len)
    {
        low=high;
    }x
    vector<vector<char>> charMatrix(low,vector<char>(high));
    for(int i=0;i<high;i++)
    {
        for(int j=0;j<low;j++)
        {
            int index=j*high+i;
            if(index>=len)
            {
                charMatrix[j][i]='*';
            }
            else
            {
                charMatrix[j][i]=s[index];
            }
        }
    }
    for(int i=0;i<high;i++)
    {
        for(int j=0;j<low;j++)
        {
            if(charMatrix[j][i]!='*')
                cout<<charMatrix[j][i];
            else
                continue;
        }
        cout<<" ";
    }
    return 0;
}
