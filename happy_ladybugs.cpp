#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int n,i,flag=0;
        cin >> n;
        string b;
        cin >> b;
        unordered_map<char,int> charMap;
        charMap['_']=0;
        for(i=0;i<n;i++)
        {
            charMap[b[i]]+=1;
        }
        for(auto it:charMap)
        {
            if(it.second==1 && it.first!='_')
            {
                flag=1;
                break;
            }
        }
        if(charMap['_']==0)
        {
            for(i=1;i<n-1;i++)
            {
                if(b[i]!=b[i-1] && b[i]!=b[i+1])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
