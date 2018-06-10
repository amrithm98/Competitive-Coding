#include <bits/stdc++.h>
using namespace std;

vector<int> z(51,0);

void zfunction(string s)
{
    int n = s.size();
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) 
    {
        if (i > R) 
        {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
        } 
        else 
        {
            int k = i-L;
            if (z[k] < R-i+1) 
            z[i] = z[k];
            else 
            {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    zfunction(s);
    cout << z[s.size()-1];
    return 0;
}