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
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long b;
        long w;
        cin >> b >> w;
        long x;
        long y;
        long z;
        cin >> x >> y >> z;
        long cost[3];
        cost[0]=b*x+w*y;
        cost[1]=(b+w)*x+w*z;
        cost[2]=(b+w)*y+b*z;
        long min=cost[0];
        for(int i=0;i<3;i++)
            if(cost[i]<min)
                min=cost[i];
        cout<<min<<"\n";
    }
    return 0;
}
