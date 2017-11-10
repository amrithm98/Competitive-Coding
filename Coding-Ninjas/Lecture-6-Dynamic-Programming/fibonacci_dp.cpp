#include <iostream>
using namespace std;

int fibonacci(int n,int *arr)
{
    if(n == 1 || n == 0)
        return 1;
    if(arr[n] > 0)
        return arr[n];
    int output = fibonacci(n-1,arr) + fibonacci(n-2,arr);
    arr[n] = output;
    return output;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n+1];
    cout<<fibonacci(n,arr)<<endl;
}