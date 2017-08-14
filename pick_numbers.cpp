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
    vector<int> a(n);
    vector<int> count(100);
    for(int i = 0;i < n;i++){
       cin >> a[i];
       count[a[i]]++;
    }
    int max=0;
    for(int i=0;i<n-1;i++)
    {
        if(count[i]+count[i+1]>max)
        {
            max=count[i]+count[i+1];
        }
    }
    cout<<max;
    return 0;
}
