#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    long n;
    cin>>n;
    vector<long> array(n);
    unordered_map<long,long> countMap;
    for(long i=0;i<n;i++)
    {
        cin>>array[i];
        countMap[array[i]]++;
    }
    long q;
    cin>>q;
    for(long i=0;i<q;i++)
    {
        int val;
        cin>>val;
        cout<<countMap[val]<<endl;
    }
    return 0;
}
