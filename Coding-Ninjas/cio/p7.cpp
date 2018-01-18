#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = INT_MIN;
    int *arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] > max)
            max = arr[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == max)
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}