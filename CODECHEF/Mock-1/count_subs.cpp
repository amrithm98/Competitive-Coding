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

        char s[100001];
        scanf("%s",s);

        long long int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                cnt++;
            }
        }   

        long long int ans = ((cnt*(cnt+1))/2);
        printf("%llu\n",ans);
    }
    return 0;
}