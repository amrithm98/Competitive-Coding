#include <iostream>
#include <algorithm>
using namespace std;


void sort012(int arr[], int n)  {  
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing output is handled automatically.
     */
  int nextz = 0;
  int last2 = n-1;
  for(int i = 0; i < n; i++)
  {

    if(arr[i] == 2 && i < last2)
    {
      swap(arr[i],arr[last2]);
      last2--;
      i--;
    }
    else if(arr[i] == 0)
    {
      swap(arr[i],arr[nextz]);
      nextz++;
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

    sort012(arr,n);

    cout << endl;

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}