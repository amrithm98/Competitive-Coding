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
int maxVal(int a,int b)
{
    if(a>b)
        return a;
    else 
        return b;

}

int getMaxCost(vector<int> B)
{
    long n=B.size();
    long j=0;
    int high=0,low=0,highNext,lowNext,highLowDiff,lowHighDiff,highHighDiff;
    for(j=1;j<n;j++)
    {
        highLowDiff=abs(B[j-1]-1);
        lowHighDiff=abs(B[j]-1);
        highHighDiff=abs(B[j]-B[1-1]);

        lowNext=maxVal(low,high+highLowDiff);
        highNext=maxVal(high+highHighDiff,low+lowHighDiff);

        low=lowNext;
        high=highNext;

    }
    return maxVal(high,low); 
}
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    for(int t0=0;t0<t;t0++)
    {
        long n;
        cin>>n;
        vector<int> B(n);
        for(long i=0;i<n;i++)
            cin>>B[i];
        cout<<"\nAns: "<<getMaxCost(B)<<endl;
    }
    return 0;
}
