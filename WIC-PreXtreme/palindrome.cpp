#include <iostream>
#include <cstring>
#include<vector>
#include<unordered_map>
using namespace std;

int deletion_palin(string s,int len)
{
    int n=len;
    int dp[n][n];
    
    for(int i=0;i<n;i++)
        dp[i][i]=0;
    
    for(int k=2;k<=n;k++)
    {
        for(int j=0;j<n-k+1;j++)
        {
            int next=j+k-1;
            if(s[j]==s[next] && k==2)
                dp[j][next]=2;
            else if(s[j]==s[next])
                dp[j][next]=dp[j+1][next-1]+2;
            else    
                dp[j][next]= max(dp[j][next-1],dp[j+1][next]);
            
        }
    }
    return dp[0][n-1];
}
int main()
{
    int n;
    cin>>n;
    for(int t=0;t<n;t++)
    {
        int len;
        cin>>len;
        string s;
        cin>>s;
        unordered_map<char,int> countMap;
        for(int i=0;i<len;i++)
        {
            countMap[s[i]]++;
        }
        int deletions=0,odd=0,even=0;
        for(auto it:countMap)
        {
            // cout<<it.first<<"\t";
            if(it.second%2==1)
                odd++;
            else    
                even++;
        }
        cout<<odd-1<<"\n";
    }
    return 0;
}
