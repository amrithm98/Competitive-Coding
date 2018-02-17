#include<iostream>
using namespace std;

int main() 
{
	int n;
    cin >> n;

    int fillPos = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 2*n; j++)
        {
            if(j <= fillPos)
            {
                cout << j;
            }

            else if( j >= 2*n - fillPos + 1 )
            {
                cout << (2*n-j)+1;
            }

            else
            {
                cout << " ";
            }
        }
        cout << endl;
        fillPos++;
    }
}
