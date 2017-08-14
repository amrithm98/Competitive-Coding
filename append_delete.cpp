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

int main()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    int i=0;
    while(s[i]==t[i])
    {
        i++;
    }
    int diff=s.size()+t.size()-2*i;
    string res=((diff <= k && diff%2 == k%2) || s.size() + t.size() < k ? "Yes" : "No");
    cout<<res;
    return 0;
}
