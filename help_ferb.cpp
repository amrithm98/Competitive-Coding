#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    map<char,int> mapSum;
    for(int i=0;i<s.size();i+=2)
    {
        mapSum[s[i]]++;
    }
    
    return 0;

}
