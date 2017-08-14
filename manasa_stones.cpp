#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    int q;
    cin>>q;
    for(int a0=0;a0<q;a0++)
    {
        int n,a,b,i,j;
        cin>>n>>a>>b;
        set<int> finalSet;
        set<int >::iterator it;
        n--;
        for(int i=0;i<=n;i++)
        {
          int combo=i*a+(n-i)*b;
          finalSet.insert(combo);
        }
        for(it=finalSet.begin();it!=finalSet.end();++it)
            cout<<*it<<" ";
        cout<<"\n";
    }
    return 0;
}
