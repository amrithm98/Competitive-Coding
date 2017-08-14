#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() 
{
    int n,k;
    cin>>n>>k;
    int i,j;
    vector<int> nos(n);
    unordered_map<int,int> map;
    for(i=0;i<n;i++)
    {
        cin>>nos[i];
        map[nos[i]%k]+=1;
    }
    int count=min(map[0],1);
    for(i=1;i<(k/2)+1;i++)
    {
        if(i!=k-i)
        {
            count+=max(map[i],map[k-i]);
        }
    }
    if(k%2==0)
        count+=1;
    cout<<count;
    return 0;
}
