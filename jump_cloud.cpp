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
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    int moves=0;
    for(int i=0;i<n-1;)
    {
        if((c[i+2]==0 && c[i+1]==0) ||(c[i+2]==0 && c[i+1]==1))
        {
            moves+=1;
            i+=2;
        }
        else if(c[i+2]!=0 && c[i+1]==0)
        {
            moves+=1;
            i+=1;
        }
    }
    cout<<moves;
    return 0;
}
