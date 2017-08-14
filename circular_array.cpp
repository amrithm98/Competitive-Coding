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
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    vector<int> rot(a);
    vector<int> query(q);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    for(int a0 = 0; a0 < q; a0++){
        cin >>query[a0];
    }
    k=k%n;
    for(int i = 0; i < n; i++){
        rot[i]=a[(i+n-k)%n];
    }
    for(int i=0;i<q;i++)
    {
        cout<<rot[query[i]]<<"\n";
    }
    return 0;
}
