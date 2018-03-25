#include<bits/stdc++.h>
using namespace std;
#define LL unsigned long long int

struct Node
{
  	int x,y;
  	LL height;
};

struct Prev
{
    int x,y;
};

bool isBoundary(int i,int j,int n,int m)
{
  	if(i == 0 || j == 0 || i== n-1 || j == m-1)
    {
      	return true;
    }
  	return false;
}

void printPath(LL **grid,int n,int m,LL jump, int dx,int dy)
{
  
  	bool **visited = new bool*[n];
  	for(int i = 0;i < n; i++)
    {
      	visited[i] = new bool[m];
      	for(int j = 0; j < m; j++)
          	visited[i][j] = 0;
    }

    Prev **parent = new Prev*[n];
  	for(int i = 0; i < n; i++)
    {
      	parent[i] = new Prev[m];
      	for(int j = 0; j < m; j++)
        {
            parent[i][j].x = -1;
            parent[i][j].y = -1;
        }
    }

    parent[dx][dy].x = dx;
    parent[dx][dy].y = dy;
  
  	Node nod = {dx,dy,grid[dx][dy]};
  	queue<Node> q;
  	q.push(nod);
  	
  	int x[] = {-1,0,1,0};
  	int y[] = {0,-1,0,1};
  
  	Node finalNode;
  	bool flag = false;

    visited[dx][dy] = true;

  	while(!q.empty())
    {
      	nod = q.front();
        // cout << "\nYAYYY: " <<nod.x << " " << nod.y << endl;
      	q.pop();
            
      	if(isBoundary(nod.x,nod.y,n,m))
        {
          	finalNode = nod;
          	flag = true;
          	break;
        }
      	for(int i = 0; i < 4; i++)
        {
          	int next_x = nod.x+x[i];
          	int next_y = nod.y+y[i];
          	
          	if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)
            {
              if(!visited[next_x][next_y] && (grid[nod.x][nod.y] - grid[next_x][next_y] > 0 ) && (grid[nod.x][nod.y] - grid[next_x][next_y] <= jump ) )
              {
                  Node next = {next_x,next_y,grid[next_x][next_y]};
                  visited[next_x][next_y] = true;
                  parent[next_x][next_y].x = nod.x;
                  parent[next_x][next_y].y = nod.y;

                  q.push(next);
              }
            }
          	
        }
	}
  
  	if(!flag)
      	cout << "NO" << endl;
  	else
    {
        cout << "YES" << endl;
        vector<Prev> path;
        Prev prev = {finalNode.x,finalNode.y};

        while(prev.x != dx || prev.y != dy)
        {
            path.push_back(prev);
            prev = parent[prev.x][prev.y];
        }
        
        cout << path.size() + 1 << endl;

        cout << dx+1 << " " << dy+1 << endl;
        for(int i = path.size() -1; i >= 0; i--)
        {
            cout << path[i].x+1 << " " << path[i].y+1 << endl;
        }
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
  
  	int dx,dy;
  	LL jump;
  	
  	cin >> dx >> dy >> jump;
  	dx--;
  	dy--;
    printPath(grid,n,m,jump,dx,dy);

    return 0;
}