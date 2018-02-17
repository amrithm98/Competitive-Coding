#include <iostream>
using namespace std;


void printPattern(int n)
{
    for(int i = 1; i <= n; i += 2)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << ((i-1)*n)+j << " ";
        }
        cout << endl;
    }

    int k;
    
    if(n % 2 == 0)
    {
        k = n;
    }
    else
    {
        k = n-1;
    }

    for(int i = k; i > 0; i -= 2)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << ((i-1)*n)+j << " ";
        }
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