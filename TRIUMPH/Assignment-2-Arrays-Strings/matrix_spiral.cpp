#include <iostream>
using namespace std;

void spiralPrint(int input[][1000], int row, int col){
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	* Taking input is handled automatically.
	*/
    int row_start = 0;
    int col_start = 0;

    while( row > 0 && col > 0 && row_start < row && col_start < col)
    {
        for(int i = col_start; i < col; i++)
        {
            cout << input[row_start][i] << " ";
        }

        row_start++;
        for(int j = row_start; j < row; j++)
        {
            cout << input[j][col-1] << " ";
        }
        col--;

        for(int i = col - 1; i >= col_start; i--)
        {
            cout << input[row-1][i] << " ";
        }

        row--;

        for(int j = row - 1; j >= row_start; j--)
        {
            cout << input[j][col_start] << " ";
        }

        col_start++;
    }
}

int main()
{
    int n,m;
    cin >> n >> m;

    int mat[1000][1000];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    spiralPrint(mat,n,m);
    return 0;

}
