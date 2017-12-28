#include <bits/stdc++.h>
using namespace std;

int fare[101][101];

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> fare[i][j];
    
    for(int i = n-2; i >= 0; i--)
    {
        fare[i][0] += min(fare[i+1][0],fare[i+1][1]);
        for(int j = 1; j < m-1; j++)
        {
            fare[i][j] += min(fare[i+1][j],min(fare[i+1][j+1],fare[i+1][j-1]));
        }
        fare[i][m-1] += min(fare[i+1][m-2],fare[i+1][m-1]);
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //         cout<<fare[i][j]<< " ";
    //     cout<<endl;
    // }

    int minCost = fare[0][0];
    for(int i = 1; i < m; i++)
    {
        if(fare[0][i] < minCost)
            minCost = fare[0][i];
    }

    cout<<minCost<<endl;

    return 0;
}
