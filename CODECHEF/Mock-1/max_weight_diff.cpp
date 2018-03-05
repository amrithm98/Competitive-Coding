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

        long long int sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        sort(arr,arr+n);

        long long int firstK = 0,lastK = 0;

        //This Screwed my ass
        k = min(k,n-k);

        for(int i = 0; i < k; i++)
        {
            firstK += arr[i];
        }

        cout << sum - 2*firstK << endl;
    }
    return 0;
}