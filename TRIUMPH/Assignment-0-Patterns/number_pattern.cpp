#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    int space = n-1;

    int num = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= space; j++)
        {
            cout << " ";
        }

        for(int j = num; j <= 2*num - 1; j++ )
        {

            cout << j ;
        }
        num++;
        space--;
        
        cout << endl;
    }
    
}
