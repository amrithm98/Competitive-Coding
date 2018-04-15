#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(),arr.end());

    int i = 0;
    int j = n-1;
    vector<int> brr(n);
    int k = 0;

    while(i < n && j >= 0)
    {
        brr[k++] = arr[j--];
        brr[k++]  = arr[i++];
    }
    for(auto it : brr)
    {
        cout << it << " ";
    }

    return 0;
}