#include <iostream>
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;

    long power = 1;

    for(int i = 1;i <= x;i++)
    {
        power *= n;
    }

    cout << power << endl;
}