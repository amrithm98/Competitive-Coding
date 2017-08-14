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
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i;
    cin>>n;
    unordered_map <int,int> a;
    for(i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        a[m]=i;
    }
    for(i=1;i<=n;i++)
    {
        int x=i;
        int t=a[x];
        x=a[t];
        cout<<x<<"\n";
    }
    return 0;
}
