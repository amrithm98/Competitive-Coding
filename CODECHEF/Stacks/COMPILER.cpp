#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        int count = 0;

        int max_corr = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '<')
            {
                count++;
            }
            else if(s[i] == '>')
            {
                count--;
            }
            if(count == 0)
            {
                max_corr = i;
            }
            else if(count < 0)
            {
                break;
            }
        }
        cout << ((max_corr == 0)?0:max_corr+1) << endl;
    }
    return 0;
}