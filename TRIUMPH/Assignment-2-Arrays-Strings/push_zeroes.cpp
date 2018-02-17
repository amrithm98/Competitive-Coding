#include <iostream>
#include <algorithm>
using namespace std;


void PushZeroesEnd(int arr[], int n)  {  
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing output is handled automatically.
     */
    int startZ = -1;
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] == 0 && startZ == -1)
        {
            startZ = i;
            i--;
        }
        if(arr[i] == 0 && arr[i+1] != 0)
        {
            swap(arr[startZ],arr[i+1]);
            startZ++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i <n; i++)
        cin >> arr[i];

    PushZeroesEnd(arr,n);

    cout << endl;

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}