#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void length_pass(string arr[],string input,string output="")
{
       

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    for(int t0=0;t0<t;t0++)
    {
        int n;
        cin>>n;
        string *arr=new string[n];
        string *output=new string[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        string input;
        cin>>input;
        length_pass(arr,input);
        
    }
    return 0;
}
