#include <bits/stdc++.h>
using namespace std;

vector<int> kSmallest(vector<int> input, int n, int k) {
	// Write your code here
	priority_queue<int> pq;
  	for(int i = 0; i < k; i++)
      	pq.push(input[i]);
  
  	for(int i = k; i < n; i++)
    {
      	if(input[i] < pq.top())
        {
          	pq.pop();
          	pq.push(input[i]);
        }
    }
  
  	vector<int> ans;
  	while(!pq.empty())
    {
      	ans.push_back(pq.top());
      	pq.pop();
    }
  
  	return ans;
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

    vector<int> ans = kSmallest(arr,n,k);

    for(auto it : ans)
        cout << it << " ";

    return 0;
}