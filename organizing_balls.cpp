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
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++)
    {
        int n;
        cin >> n;

        vector<int> containers(n),balls(n);

        for(int i = 0;i < n;i++)
        {
           for(int j = 0;j < n;j++)
           {
              int k;
              cin >> k;

              containers[i] += k;
              balls[j] += k;
           }
        }

        sort(containers.begin(),containers.end());
        sort(balls.begin(),balls.end());

        int flag = 0;

        for(int i = 0; i < n ;i++)
        {
            if(containers[i] != balls[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag)
            cout<<"Impossible"<<endl;
        else
            cout<<"Possible"<<endl;
    }
    return 0;
}
