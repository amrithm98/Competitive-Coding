#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int main()
{
    int n;
    cin >> n;

    while(n != 0)
    {
        LL *arr = new LL[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        stack<LL> histogram;
        int i = 0;

        LL max_area = 0;
        LL curr_area = 0;

        while(i < n)
        {
            if(histogram.empty() || arr[histogram.top()] <= arr[i])
            {
                histogram.push(i);
                i++;
            }
            else
            {
                int top = histogram.top();
                histogram.pop();

                curr_area = arr[top]*(histogram.empty()?i : i-1-histogram.top());
                
                max_area = max(max_area,curr_area);

            }
        }

        while(!histogram.empty())
        {
            int top = histogram.top();
            histogram.pop();

            curr_area = arr[top]*(histogram.empty()?i: i-histogram.top()-1);
            max_area = max(max_area,curr_area);
        }
        cout << max_area << endl;
        
        cin >> n;
    }

    return 0;
}