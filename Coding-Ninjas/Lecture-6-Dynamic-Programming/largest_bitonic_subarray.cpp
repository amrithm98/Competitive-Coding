#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubarray(int *input, int n) {
    
/* Don't write main().
    * the input is already passed as function argument.
    * Taking input and printing output is handled automatically.
    */
    
}

int main()
{
    int n;
    cin >> n;
    int * in = new int[n];
    for(int i = 0; i < n; i++)
        cin >> in[i];
    cout<<longestBitonicSubarray(in,n)<<endl;
    return 0;
}
