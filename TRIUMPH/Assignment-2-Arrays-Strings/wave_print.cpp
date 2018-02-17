#include <iostream>
using namespace std;

void wavePrint(int input[][1000], int row, int col){
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	* Taking input is handled automatically.
	*/  
    for(int i = 0; i < col; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < row; j++)
                cout << input[j][i] << " ";
        }
        else
        {
            for(int j = row-1; j >= 0; j--)
                cout << input[j][i] << " ";
        }
    }
}

int main()
{
    int mat[][1000] = {{1,2,3},{4,5,6},{7,8,9}};
    wavePrint(mat,3,3);
}
