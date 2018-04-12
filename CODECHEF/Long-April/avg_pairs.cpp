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

        vector<long long int> data(2002,0);

        for(int i = 0; i < n; i++)
        {
            long long int x;
            cin >> x;

            x += 1000;
            data[x]++;
        }   

        long long int pairs = 0;

        for(auto it : data)
        {
            if(it >= 2)
            {
                pairs += (it * (it - 1))/2;
            }
        }

        for(int i = 0; i <= 2000; i++)
        {
            for(int j = i+1; j <= 2000; j++)
            {
                if(data[i] != 0 && data[j] != 0)
                {
                    long long int avg = (i+j);
                    if(avg % 2 == 0 && data[avg/2] != 0)
                    {
                        // cout << i << " " << j << endl;
                        pairs += data[i]*data[j];
                    }
                }
            }
        }

        cout << pairs << endl;
    }

    return 0;
}