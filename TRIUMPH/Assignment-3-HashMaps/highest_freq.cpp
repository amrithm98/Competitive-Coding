#include<bits/stdc++.h>
using namespace std; 

int highestFrequency(int *input, int n)
{	 
    unordered_map<int,int> freqMap;
    int max_count = 1;
    int max_num = input[0];
    for(int i = 0; i < n; i++)
    {
        freqMap[input[i]]++;
        if(freqMap[input[i]] > max_count)
        {
            max_count = freqMap[input[i]];
            max_num = input[i];
        }
    }
    return max_num;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << highestFrequency(arr,n) << endl;
    return 0;
}
