#include <bits/stdc++.h>
using namespace std;

bool openings[40];

int possibleBrackets(int open,int close,int n)
{
    if(open > n || close > n)
    {
        return 0;
    }
    if(open == n && close == n)
    {
        return 1;
    }
    
    int currIndex = 2*n-open-close;

    if(open == close || openings[])
    {
        return possibleBrackets(open+1,close,n);
    }
    else if(open == n)
    {
        return possibleBrackets(open,close+1,n);
    }
    else
    {
        return possibleBrackets(open+1,close,n) + possibleBrackets(open,close+1,n);
    }
}

int main()
{
    int d;
    cin >> d;

    while(d--)
    {
        int n,k;
        cin >> n >> k;
        memset(openings,0,sizeof(openings));

        for(int i = 0; i < k ; i++)
        {
            int m;
            cin >> m;
            openings[m] = true;
        }
        
        cout<<possibleBrackets(0,0,n)<<endl;
    }

    return 0;
}