#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;

        vector<char> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        bool flag = true;
        int i;
        //Find Longest increasing sequence from right to left and take the first hump
        for(i = n-1; i >= 1; i--)
        {
            if(arr[i-1] < arr[i])
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            int j,k;
            //Find the element greater than hump from right to left
            for(j = n-1; j >= i-1; j--)
            {
                if(arr[j] > arr[i-1])
                {
                    break;
                }
            }
            // Swap these two. and reverse the inc seq from right to left
            swap(arr[j],arr[i-1]);
            for(k = 0; k <= i-1; k++)
                cout << arr[k];
            for(k = n-1; k > i-1; k--)
                cout << arr[k];

            cout << endl;
        }
        
    }

    return 0;
}