#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;    
    cin >> n;
    map<int,int> freqMap1;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        freqMap1[k]++;
    }

    cin >> m;
    map<int,int> freqMap2;
    for(int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        freqMap2[k]++;
    }

    for(auto it: freqMap2)
    {
        if(freqMap1[it.first] < it.second)
            cout<<it.first<<" ";
    }
    return 0;
}
