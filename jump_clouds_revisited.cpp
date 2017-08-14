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
    int n;
    int k;
    cin >> n >> k;

    vector<int> c(n);

    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }

    int e=100,i=0;
    for(i=k;i<n;i+=k)
    {
        // cout<<i<<"\t"<<e<<"\n";
        if(c[i]==1)
        {
            e-=3;
        }
        else
            e-=1;
    }
    if(c[0]==1)
        e-=3;
    else    
        e-=1;
    cout<<e;
    return 0;
}
