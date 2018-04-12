#include <bits/stdc++.h>
using namespace std;

bool checkSafe(int **arr, int row,int col,int n)
{
    for(int i = 0; i < col; i++)
    {
        if(arr[row][0])
            return false;
    }

    for(int i = row,j=col; i >= 0 && j >= 0; i--,j--)
    {
        if(arr[col][j])
            return false;
    }

    for(int i = row,j=col; i < n && j >= 0; i++,j--)
    {
        if(arr[row][col])
            return false;
    }
    return true;
}

bool solveNQueen(int ***arr,int &col,int *n)
{
    if(col == n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << arr[i][j] << " ";

            cout << endl;
        }
        cout << endl;
        return true;
    }

    for(int i = 0; i < n; i++)
    {
        if(checkSafe(arr,i,col,n))
        {
            arr[i][col] = 0;
            
            solveNQueen(arr,col+1,n);

            arr[i][col] = 1;
        }
    }

    return false;
}

void placeNQueen(int *n)
{
    int ***arr = new int*&[*n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = new int*[*n];
        for(int j = 0; j < n; j++)
            arr[i][j] = 1;
    }

    solveNQueen(arr,0,n);
}

int main()
{
    int n;
    cin >> n;

    placeNQueen(n);
    return 0;
}