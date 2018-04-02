#include <bits/stdc++.h>

using namespace std;

bool isInRange(int x,int y,int n,int m)
{
    if(x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}
void DFS(vector < vector<int> > matrix,vector<vector<bool>> &visited,int &compCount,int x,int y)
{
    visited[x][y] = 1;
    int posX[] = {-1,-1,-1,0,0,1,1,1};
    int posY[] = {-1,0,1,-1,1,-1,0,1};
    compCount++;
    for(int i = 0; i < 8; i++)
    {
        int next_x = x + posX[i];
        int next_y = y + posY[i];
        
        if(isInRange(next_x,next_y,matrix.size(),matrix[0].size()))
        {
            if(!visited[next_x][next_y] && matrix[next_x][next_y])
            {
                DFS(matrix,visited,compCount,next_x,next_y);
            }
        }
    }
}

int connectedCell(vector < vector<int> > matrix) {
    // Complete this function
    int max_reg = 0;
    vector<vector<bool>> visited(matrix.size(),vector<bool> (matrix[0].size(),false));
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] && !visited[i][j])
            {
                int compCount = 0;
                DFS(matrix,visited,compCount,i,j);
                max_reg = max(max_reg,compCount);
            }
        }
    }
    return max_reg;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > matrix(n,vector<int>(m));
    for(int matrix_i = 0;matrix_i < n;matrix_i++){
       for(int matrix_j = 0;matrix_j < m;matrix_j++){
          cin >> matrix[matrix_i][matrix_j];
       }
    }
    int result = connectedCell(matrix);
    cout << result << endl;
    return 0;
}
