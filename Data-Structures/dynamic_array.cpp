#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long n,q;
    cin>>n>>q;

    vector<vector<int>> seqList(n);

    long i,x,y,z;
    long lastAnswer=0;
    for(i=0;i<q;i++)
    {   
        cin>>x>>y>>z;

        long index=(y^lastAnswer)%n;
        if(x==1)
        {
            seqList[index].push_back(z);
        }
        else
        {
            long j_index=z%(seqList[index].size());
            lastAnswer=seqList[index][j_index];
            cout<<lastAnswer<<endl;
        }
    } 
    return 0;
}
