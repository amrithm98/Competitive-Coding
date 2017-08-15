#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() 
{
    int t;
    cin>>t;
    for(int a=0;a<t;a++)
    {
        string s;
        int i=0,j=0;
        cin>>s;
        bool val = next_permutation(s.begin(), s.end());
        if (val == false)
            cout << "no word" << endl;
        else
            cout<<s<<"\n";
    }
    return 0;
}
