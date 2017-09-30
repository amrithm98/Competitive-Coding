#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string findEq(vector<vector<int>> forces)
{
    int f[]={0,0,0};
   for(int i=0;i<forces.size();i++)
   {
      
       for(int j=0;j<3;j++)
       {
           f[j]+=forces[i][j];
       }
   }
   int flag=0;
   for(int i=0;i<3;i++)
   {
       if(f[i]!=0)
       {
           flag=1;
           break;
       }
   }
   if(flag)
    return "NO";
    else
        return "YES";
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<vector<int>> forces(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
               cin>>forces[i][j];
    }
    cout<<findEq(forces);
    return 0;
}
