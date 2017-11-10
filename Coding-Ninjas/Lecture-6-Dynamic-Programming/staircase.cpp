#include <bits/stdc++.h>
using namespace std;

int stairCase_naive(int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n < 0)
    {
        return 0;
    }
    return stairCase_naive(n-1)+stairCase_naive(n-2)+stairCase_naive(n-3);
}

long *arr;

long staircase(int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n < 0)
    {
        return 0;
    }
    if(arr[n] > 0)
    {
        return arr[n];
    }
    long ans = staircase(n-1)+staircase(n-2)+staircase(n-3);
    arr[n] = ans;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    arr = new long[n+1];
    if(n <= 2)
        cout<<n<<endl;
    else
    {
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
        cout<<staircase(n)<<endl;
    }
    return 0;
}