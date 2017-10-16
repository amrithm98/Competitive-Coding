#include <bits/stdc++.h>
#include <map>
#include <set>
using namespace std;

string isValid(string s){
    // Complete this function
    map<char,int> charMap;
    int len=s.size();

    int i;

    for(i=0;i<len;i++)
    {
        charMap[s[i]]++;
    }

    map<int,int> freqCount;

    for(auto it:charMap)
    {
        freqCount[it.second]++;
    }

    int flag=0;
    if(freqCount.size()==1)
        return "YES";
    
    if(freqCount.size()==2)
    {
        int arr[2][2];
        int i=0;
        for(auto it:freqCount)
        {
            // cout<<endl<<it.first<<" "<<it.second;
            if(it.first==1 && it.second==1)
                return "YES";
            arr[i][0]=it.first;
            arr[i][1]=it.second;
            i++;
        }         
        for(int i=0;i<2;i++)
        {
            if(arr[i][1]==1)
            {
                if(i==1)
                {
                    if((arr[1][0]-arr[0][0])==1)
                        return "YES";
                }
                else
                {
                    if((arr[0][0]-arr[1][0])==1)
                        return "YES";
                }
            }
        }   
    }
    return "NO";
   
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
