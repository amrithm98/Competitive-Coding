#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int half = n/2;
    int x = half;
    
    for(int i = 2; i <= half; i++)
        cout << i << " ";

    cout << 1 << " ";

    for(int i = half + 2; i <= n; i++)
        cout << i << " ";
    cout << half + 1 << endl;

    cout << n << " ";
    for(int i = 1; i < n; i++)
        cout << i << " ";

    return 0;
}