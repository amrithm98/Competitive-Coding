#include<bits/stdc++.h>
using namespace std;

int minDistance(int arr[],int n)
{
    unordered_map<int,int> freqMap;
    int min_rep = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(freqMap[arr[i]] == 0)
        {
            freqMap[arr[i]] = i+1;
        }
        else
        {
            min_rep = min(min_rep,(i - freqMap[arr[i]] + 1) );
            freqMap[arr[i]] = i+1;
        }
    }

    if(min_rep == INT_MAX)
      	return -1;
  	else return min_rep;
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
