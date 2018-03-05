#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;

        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if( (arr[i] + k) % 7 == 0 )
                count++;
        }
        cout << count << endl;
    }
    return 0;
}