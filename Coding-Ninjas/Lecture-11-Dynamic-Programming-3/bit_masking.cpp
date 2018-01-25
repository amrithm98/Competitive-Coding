#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Set ith bit of a number;
    int n = 11;
    //set 2nd bit of n to 1 (from LSB)
    cout << (n | (1 << 2)) << endl;
    //Ret 1st bit of n to 0 (from LSB)
    cout << (n & ~(1 << 1)) << endl;
    return 0;
}