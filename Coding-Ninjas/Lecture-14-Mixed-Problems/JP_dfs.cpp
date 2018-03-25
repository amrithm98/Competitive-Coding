#include<bits/stdc++.h>
using namespace std;
#define LL unsigned long long int

bool visited[501][501];

bool flag = false;

struct Node
{
  	int x,y;
  	LL height;
};

struct Prev
{
    int x,y;
};

vector<Prev> path;

bool isBoundary(int i,int j,int n,int m)
{
  	if(i == 0 || j == 0 || i== n-1 || j == m-1)
    {
      	return true;
    }
  	return false;
}

void dfs(LL **grid,int n,int m,LL jump, int dx,int dy)
{
    visited[dx][dy] = 1;

    if(isBoundary(dx,dy,n,m))
    {
        flag = true;
        return;
    }

    if( (dx-1) >= 0 && !visited[dx-1][dy] && (grid[dx][dy]-grid[dx-1][dy]) <= jump && (grid[dx][dy]-grid[dx-1][dy]) > 0)
    {
        path.push_back(Prev{dx-1,dy});
        dfs(grid,n,m,jump,dx-1,dy);
    }

    else if( (dy-1) >= 0 && !visited[dx][dy-1] && (grid[dx][dy]-grid[dx][dy-1]) <= jump && (grid[dx][dy]-grid[dx][dy-1]) > 0)
    {
        path.push_back(Prev{dx,dy-1});
        dfs(grid,n,m,jump,dx,dy-1);
    }
    else if( (dx+1) < n && !visited[dx+1][dy] && (grid[dx][dy]-grid[dx+1][dy]) <= jump && (grid[dx][dy]-grid[dx+1][dy]) > 0)
    {
        path.push_back(Prev{dx+1,dy});
        dfs(grid,n,m,jump,dx+1,dy);
    }
    else if( (dy+1) >= 0 && !visited[dx][dy+1] && (grid[dx][dy]-grid[dx][dy+1]) <= jump && (grid[dx][dy]-grid[dx][dy+1]) > 0)
    {
        path.push_back(Prev{dx,dy+1});
        dfs(grid,n,m,jump,dx,dy+1);
    }
}

int main()
{
    //Write your code here
  	int n,m;
  	cin >> n >> m;
  		
  	LL **grid = new LL*[n];
  	for(int i = 0; i < n; i++)
      	grid[i] = new LL[m];
  
  	for(int i = 0; i < n; i++)
    {
      	for(int j = 0; j < m; j++)
          	cin >> grid[i][j];
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            visited[i][j] = 0;
    }

  	int dx,dy;
  	LL jump;
  	
  	cin >> dx >> dy >> jump;
  	dx--;
  	dy--;
    dfs(grid,n,m,jump,dx,dy);

    if(flag)
    {
        cout << "YES" << endl;
        cout << path.size()+1 << endl;
        cout << dx+1 << " " << dy+1 << endl;
        for(auto it : path)
        {
            cout << it.x+1 << " " << it.y+1 << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}