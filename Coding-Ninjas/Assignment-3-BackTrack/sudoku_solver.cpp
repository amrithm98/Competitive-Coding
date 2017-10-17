#include<iostream>
using namespace std;

bool checkPossible(int board[][9],int row,int col,int val)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==val)
            return false;

        if(board[i][col]==val)
            return false;
    }
    int row_start=(row/3)*3;
    int col_start=(col/3)*3;

    int row_end=row_start+3;
    int col_end=col_start+3;

    for(int i=row_start;i<row_end;i++)
    {
        for(int j=col_start;j<col_end;j++)
        {
            if(board[i][j]==val)
                return false;
        }
    }
    return true;
}

bool gridFull(int board[][9],int &row,int &col)
{
    for(row=0;row<9;row++)
        for(col=0;col<9;col++)
            if(board[row][col] == 0)
                return false;
    return true;
}

void printBoard(int board[][9])
{
    cout<<"\nSolved!!"<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    int row,col;

    if(gridFull(board,row,col))
    {
        // printBoard(board);
        return true;
    }    
    
    for(int i=1;i<=9;i++)
    {
        if(checkPossible(board,row,col,i))
        {
            board[row][col]=i;

            if(sudokuSolver(board))
                return true;
            
            board[row][col]=0;
        }
    }

    return false;
}


int main()
{
    int board[9][9];

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>board[i][j];
        }
    }

    if(sudokuSolver(board))
        cout<<"true"<<endl;
    else    
        cout<<"false"<<endl;
}