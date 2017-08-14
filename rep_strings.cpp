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
    long n,i;
    cin >> n;
    long len=s.length();
    long quo=n/len;
    long rem=n%len;
    int nos_a=count(s.begin(),s.end(),'a');
    long sum=0;
    int rem_a=count(s.begin(),s.begin()+rem,'a');
    sum+=(nos_a*quo+rem_a);
    cout<<sum;
    return 0;
}
