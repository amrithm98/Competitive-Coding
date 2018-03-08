#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr,arr+n,greater<int>());

    unsigned long long int miles = 0,power2 = 1;
    for(int i = 0; i < n; i++)
    {
        miles += (power2*arr[i]);
        power2 *= 2;
    }
    cout << miles << endl;
    return 0;
}