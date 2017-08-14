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
    long n;
    long m;
    int i;
    cin >> n >> m;
    vector<long> c(m);
    for(long c_i = 0;c_i < m;c_i++){
        cin >> c[c_i];
    }
    sort(c.begin(),c.end());
    // for(i=0;i<m;i++)
    //     cout<<c[i]<<"\t";
    // cout<<"\n";
    int max_dist=0;
    for(i=0;i<m-1;i++)
    {
        int temp=abs(abs(c[i]-c[i+1])-1);
        if(max_dist<temp)
            max_dist=temp;
    }
    int final_dist=0;
    int diff_with_last=(abs(c[m-1]-n)-1);
    if(max_dist==0)
            final_dist=0;
    else if(max_dist%2==0)
            final_dist=max_dist/2;
    else
            final_dist=(max_dist/2)+1;

    if(c[0]>final_dist && c[0]>diff_with_last)
    {

        final_dist=c[0];
    }
    else if(diff_with_last>=final_dist)
    {
        final_dist=diff_with_last;
    }
    cout<<final_dist;
    return 0;
}
