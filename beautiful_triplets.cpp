#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n,d;
    cin>>n>>d;
    vector<int> sequence(n);
    for(int i=0;i<n;i++)
        cin>>sequence[i];
    int count=0;
    for(int i=0;i<n;i++)
    {
        int val=sequence[i];
        bool x=binary_search(sequence.begin(),sequence.end(),val+d);
        bool y=binary_search(sequence.begin(),sequence.end(),val+2*d);
        if(x && y)
            count+=1;
    }
    cout<<count;
    return 0;
}
