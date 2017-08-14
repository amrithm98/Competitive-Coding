#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i,j;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            int elem=grid[i][j]-'0';
            if(elem>(grid[i-1][j]-'0') && elem>(grid[i+1][j]-'0') && elem>(grid[i][j+1]-'0') && elem>(grid[i][j-1]-'0'))
            {
                grid[i][j]='X';
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<grid[i]<<"\n";
    }
    return 0;
}
