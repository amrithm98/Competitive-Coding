#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int main()
{

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--)
    {
        string s;
        LL n;

        cin >> s >> n;
        vector<LL> pos(s.size());
        
        int var = 0;
        int post = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a')
                var++;
            else
                var--;
            pos[i] = var;

            if(var > 0)
                post++;
        }

        if(post == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if(pos[s.size()-1] == 0)
        {
            LL ans = ((long long int)post*n);
            cout << ans << endl;
            continue;
        }

        long long int sum = 0;
        long long int cd = pos[s.size()-1];
        
        for(int i = 0; i < s.size(); i++)
        {
            if(pos[i] <= 0 && cd <= 0)
            {
                continue;
            }
            if(pos[i] > 0 && cd > 0)
            {
                sum += n;
                continue;
            }
            if(pos[i] <= 0)
            {
                long long int x = 1;
                while(x*cd + pos[i] <= 0)
                {
                    x++;
                }
                sum += (n-x);
            }
            else
            {
                long long int x = 1;
                while(x*cd + pos[i] > 0)
                {
                    x++;
                }
                sum += min(n,x);
                continue;
            }
        }
        cout << sum << endl;
    }

    return 0;
}