#include <bits/stdc++.h>
using namespace std;


void lisOptim(int *arr, int n)
{
    vector<int> tail;
    tail.push_back(arr[0]);

    for(int i = 1; i < n; i++)
    {
        int val = arr[i];

        if(val < tail[0])
        {
            tail[0] = val;
        }
        else if(val > tail[tail.size()-1])
        {
            tail.push_back(val);
        }
        else
        {
            int ceilIndex = lower_bound(tail.begin(),tail.end(),val) - tail.begin();
            tail[ceilIndex] = val;
        }
    }

    cout << tail.size() << endl;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    lisOptim(arr,n);
    return 0;
}