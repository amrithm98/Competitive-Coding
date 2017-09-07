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

int countSteps(vector<int> data,int min)
{
    int steps=0;
    for(int i=0;i<data.size();i++)
    {
        int req_diff=data[i]-min;
        while(req_diff!=0)
        {
            // cout<<"\nReq Diff: "<<req_diff;
            if(req_diff>=5)
            {
                data[i]-=5;
            }
            else if(req_diff>=2 && req_diff<5)
            {   
                data[i]-=2;
            }
            else if(req_diff<2)
            {
                data[i]-=1;
            }
            req_diff=data[i]-min;
            steps++;
        }
        // cout<<"\n";
        // for(int i=0;i<data.size();i++)
        // {
        //     cout<<data[i]<<" ";
        // }
    }
    return steps;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    for(int t0=0;t0<t;t0++)
    {
        int n;
        cin>>n;
        vector<int> choc_count(n);
        vector<int> min_steps;
        for(int i=0;i<n;i++)
        {
            cin>>choc_count[i];
        }
        int min=(*min_element(choc_count.begin(),choc_count.end()));
        min_steps.push_back(countSteps(choc_count,min));
        min_steps.push_back(countSteps(choc_count,min-1));
        min_steps.push_back(countSteps(choc_count,min-2));
        cout<<(*min_element(min_steps.begin(),min_steps.end()))<<endl;

    }
    return 0;
}
