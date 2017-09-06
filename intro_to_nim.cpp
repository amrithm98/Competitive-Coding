#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q;
    cin>>q;
    for(int m=0;m<q;m++)
    {
        int n;
        cin>>n;
        int nimsum=0;
        vector<int> piles(n);
        for(int i=0;i<n;i++)
        {
            cin>>piles[i];
        }
        nimsum=piles[0];
        for(int i=1;i<n;i++)
        {
            nimsum^=piles[i];
        }
        if(nimsum)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;

    } 
    return 0;
}
