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
    string s;
    cin >> s;
    int n;
    cin >> n;
    unordered_map<char,int> map;
    for(int i=0;i<s.size();i++)
        map[s[i]]+=1;

    vector<int> sizes;
    vector<int>::iterator vecIt;
    for(auto it:map)
    {
        int char_cost=int((it.first)-96);
        for(int j=1;j<=it.second;j++)
            sizes.push_back(j*char_cost);
    }   
    // for(int i=0;i<sizes.size();i++)
    //     cout<<sizes[i]<<"\n";
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        vecIt=find(sizes.begin(),sizes.end(),x);
        if(vecIt!=sizes.end())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
