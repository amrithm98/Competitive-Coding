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


int minTransmitters(vector<int> &x, int n,int k)
{
    
    int i = 0;

    int transmitter = 0;

    while(i<n)
    {
        transmitter++;
        int end_area = x[i] + k;
        // cout<<"\nEnd 1: "<<end_area<<endl;
        while(i < n && x[i] <= end_area)
        {
            i++;
        }
        end_area = x[--i] + k;
        // cout<<"\nEnd 2: "<<end_area<<endl;
        while(i < n && x[i] <= end_area)
            i++;
    }
    return transmitter;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    for(int x_i = 0;x_i < n;x_i++){
       cin >> x[x_i];
    }
    sort(x.begin(),x.end());

    cout << minTransmitters(x,n,k) << endl;

    return 0;
}
