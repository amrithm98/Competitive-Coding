#include<bits/stdc++.h>
using namespace std;

int minDistance(int arr[],int n)
{
    unordered_map<int,int> freqMap;
    for(int i = 0; i < n; i++)
    {
        if(freqMap[arr[i]] == 0)
        {
            freqMap[arr[i]] = i+1;
        }
        else
        {
            return (i - freqMap[arr[i]] + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << minDistance(arr,n) << endl;
    return 0;
}
