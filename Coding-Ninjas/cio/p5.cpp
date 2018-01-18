#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;

    for(int i = 1; i <= n; i++)
    {   
        if(i < n-i)
        {
            count++;
        }
        else
            break;
    }
    cout<<count<<endl;
    return 0;
}