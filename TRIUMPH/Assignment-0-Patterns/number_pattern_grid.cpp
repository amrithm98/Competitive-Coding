#include <iostream>
using namespace std;


void printPattern(int n)
{
    int print = n;
    int range = n;

    for(int i = 1; i <= 2*n - 1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j >= range)
            {
                cout << n-j << " ";
            }
            else
            {
                cout << n << " ";
            }
        }
        for(int j = n+1; j <= 2*n-1; j++)
        {
            if(j <= 2*n-range)
            {
                cout << 2*n-1-j << " ";
            }
            else
            {
                cout << n << " ";
            }
        }
        range--;
        cout << endl;
    }

}

int main()
{
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}