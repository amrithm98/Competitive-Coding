#include<bits/stdc++.h>
using namespace std;

int minCost(int **arr,int n,int m)
{
    map<int,int> visited;

    int sum = 0;
    for(int i = 0; i < m; i++)
    {
        int min = INT8_MAX;
        int req_ind = -1;
        for(int j = 0; j < n; j++)
        {
            if(arr[j][i] < min && !visited[j])
            {
                min = arr[j][i];
                req_ind = j;
            }
        }
        visited[req_ind] ++;
        sum += min;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int **arr = new int*[n];
        for(int i = 0; i < n; i++)
            arr[i] = new int[m];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
        cout<<minCost(arr,n,m)<<endl;
    }
}