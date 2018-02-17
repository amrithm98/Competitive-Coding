#include<iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;

    int space = 0;
    int count = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < space; j++)
        {
            cout << " ";
        }

        for(int k = 1; k <= count; k++)
        {
            cout << "* ";
        }

        if(i <= n/2)
        {
            count++;
            space++;
        }
        else
        {
            count--;
            space--;
        }
        
        cout << endl;
    }
}


