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
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k,i,j;
        cin >> n >> k;
        vector<int> nos(n);
        for(i=1;i<=n;i++)
            nos[i-1]=i;
        vector<int> possiblePermutation(n);
        if(k==0)
        {
            possiblePermutation=nos;
        }
        else
        {
            for(i=0,j=1;i<n;i++)
            {
                if(i==(j+1)*k)
                {
                    j+=2;
                }
                if(i<j*k)
                {
                    possiblePermutation[i]=abs(nos[i]+k);
                }
                else if(i>=j*k && i<(j+1)*k)
                {
                    possiblePermutation[i]=abs(nos[i]-k);
                }
            }
        }
        
        int flag=0;
        for(i=0;i<n;i++)
        {
            if(possiblePermutation[i]>n)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            cout<<-1;
        else
        {
            for(i=0;i<n;i++)
                cout<<possiblePermutation[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
