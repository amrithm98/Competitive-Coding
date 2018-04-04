#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the knightlOnAChessboard function below.
 */
bool isInRange(int x,int y,int n)
{
    if(x >= 0 && y >= 0 && x < n && y < n)
        return true;
    return false;
}

int BFS(int n,int a,int b,bool **visited)
{
    int posX[] = {a,a,-a,-a,b,b,-b,-b};
    int posY[] = {b,-b,b,-b,a,-a,a,-a};
    
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0] = true;
    
    int **level = new int*[n];
    for(int i = 0; i < n; i++)
    {
        level[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            level[i][j] = 0;
        }
    }
    
    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        q.pop();
        
        if(curr.first == n-1 && curr.second == n-1)
        {
            return level[curr.first][curr.second];
        }
        
        for(int i = 0; i < 8; i++)
        {
            int next_x = curr.first + posX[i];
            int next_y = curr.second + posY[i];
            
            if(isInRange(next_x,next_y,n) && !visited[next_x][next_y])
            {
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x,next_y));
                level[next_x][next_y] = level[curr.first][curr.second]+1;
            }
        }
    }
    
    return -1;
    
}
vector<vector<int>> knightlOnAChessboard(int n) {
    /*
     * Write your code here.
     */
    vector<vector<int>> pathMatrix(n-1,vector<int>(n-1));
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            bool **visited = new bool*[n];
            for(int k = 0; k < n; k++)
            {
                visited[k] = new bool[n];
                for(int l = 0; l < n; l++)  
                    visited[k][l] = 0;
            }
            
            pathMatrix[i-1][j-1] = BFS(n,i,j,visited);
        }
    }
    return pathMatrix;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}