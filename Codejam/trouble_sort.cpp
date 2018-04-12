#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int cnt = 1;

    while(t--)
    {
        int n;
        cin >> n;

        LL *arr = new LL[n];

        LL **evenOdd = new LL*[2];
        for(int i = 0; i < n; i++)
            evenOdd[i] = new LL[n];

        bool flag = 0;

        int odd_count = 0,even_count = 0;

        for(int i =  0; i < n; i++)
        {
            cin >> arr[i];
            evenOdd[flag][i/2] = arr[i];

            if(flag)
                odd_count++;
            else
                even_count++;

            flag = !flag;
        }

        // for(int i = 0; i < 2; i++)
        // {
        //     for(int j = 0; j < n/2 + 1; j++)
        //         cout << evenOdd[i][j] << " ";
        //     cout << endl;
        // }

        // cout << odd_count << " " << even_count << endl;

        sort(arr,arr+n);
        sort(evenOdd[0],evenOdd[0]+even_count);
        sort(evenOdd[1],evenOdd[1]+odd_count);

        int i = 0;
        flag = 0;

        for(; i < n; i++)
        {
            // cout << arr[i] << " " << evenOdd[flag][i/2] << endl;
            if(arr[i] != evenOdd[flag][i/2])
                break;

            flag = !flag;
        }

        cout << "Case #" << cnt << ": ";

        if(i == n)
        {
            cout << "OK\n";
        }
        else
            cout << i << endl;

        cnt++;
    }

    return 0;
}