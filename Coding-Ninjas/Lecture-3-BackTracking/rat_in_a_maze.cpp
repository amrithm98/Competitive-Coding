
#include<iostream>
#include<cstring>
using namespace std;


bool checkMovable(int maze[][20],int row,int col,int n)
{
    if(row>=n || row<0 || col<0 || col>=n || maze[row][col]!=1)
        return false;
    else
        return true;   
}

void ratHelper(int maze[][20],int n,int path[][20],int row,int col)
{
    if(row==n-1 && col==n-1)
    {
        path[row][col]=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<path[i][j]<<" ";
        }
        cout<<endl;
        return;
    }

    if(checkMovable(maze,row,col,n) && path[row][col]!=1)
    {
        path[row][col]=1;
        ratHelper(maze,n,path,row-1,col);  
        ratHelper(maze,n,path,row+1,col);  
        ratHelper(maze,n,path,row,col-1);  
        ratHelper(maze,n,path,row,col+1);  
        path[row][col]=0;
    }
    
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  int path[20][20];
  memset(path,0,sizeof(path[0][0])*20*20);
  ratHelper(maze,n,path,0,0);
}

int main()
{
    int n;
    cin>>n;
    int maze[20][20];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>maze[i][j];

    ratInAMaze(maze,n);
}
