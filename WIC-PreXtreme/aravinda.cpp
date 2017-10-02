#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
    long n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        string s=bitset<64>(x).to_string();
        cout<<count(s.begin(),s.end(),'1')<<endl;
    }
    return 0;
}
