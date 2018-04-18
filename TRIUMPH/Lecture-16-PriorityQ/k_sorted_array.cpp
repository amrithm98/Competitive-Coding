#include <bits/stdc++.h>
using namespace std;

void kSorted(vector<int> &arr,int n,int k)
{
    priority_queue<int> pq;
    for(int i = 0; i < k; i++)
        pq.push(arr[i]);

    int j = 0;
    for(int i = k; i < n; i++)
    {
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    while(!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    kSorted(arr,n,k);

    for(auto it : arr)
        cout << it << " ";

    return 0;
}

//5 3
//10 11 12 6 9
//12 11 10 9 6