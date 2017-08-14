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
        long t,n=2;
        cin >> t;
        while(3*(n-1)<t)
        {
            n*=2;
        }
        cout<<3*(n-1)-t+1;
        // int i;
        // int a=3,r=2;  
        // int count=0; 
        // int n=t; 
        // int n_term,n_max;
        // for(i=1;i<=n/2;i++)
        // {   
        //     count+=1;
        //     n_term=a*pow(r,i-1);
        //     n_max=a*(pow(r,i)-1);
        //     if(n<=n_max)
        //     {
        //         break;
        //     }
        // }
        // // cout<<n_max;//n_max corresponds to time 1;
        // int diff=n_max-n_term+1;
        // int pointer=t-diff;
        // cout<<n_term-pointer;
        return 0;
    }
