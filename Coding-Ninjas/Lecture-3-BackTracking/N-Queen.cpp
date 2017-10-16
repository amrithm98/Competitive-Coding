#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkSafe(vector<vector<int>> queenBoard,int row,int col,int n)
{
    for(int i=0;i<col;i++)
    {
        if(queenBoard[row][i])
            return false;
    }

    for(int i=row,j=col; j>=0 && i>=0 ; j--,i--)
    {
        if(queenBoard[i][j])
            return false;
    }

    for(int i=row,j=col; j>=0 && i<n ; i++,j--)
    {
        if(queenBoard[i][j])
            return false;
    }
    
    return true;
}

bool solveNQueen(vector<vector<int>> queenBoard,int col,int n)
{
    int i,j;

    if(col==n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<queenBoard[i][j]<<" ";
            }
        }
        cout<<endl;
        return true;
    }

    for(i=0;i<n;i++)
    {
        if(checkSafe(queenBoard,i,col,n))
        {

            queenBoard[i][col]=1;

            solveNQueen(queenBoard,col+1,n);

            queenBoard[i][col]=0;
        }
    }

    return false;
}

void placeNQueens(int n)
{
    vector<vector<int>> queenBoard(n,vector<int> (n));
    solveNQueen(queenBoard,0,n);
}

int main()
{
    int n;
    cin>>n;
    placeNQueens(n);
}