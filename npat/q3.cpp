#include <iostream>

using namespace std;

int has(int *a, int n, int x, int k) {
    if(k==0)
        return 1;
    if(n==0 && k!=0)
        return 0;
  if(a[n-1] == x) {
    return has(a, n-1, x, k-1);
  } else {
    return has(a, n-1, x, k);
  }
}
int main()

{
    int a[]={1,2,3,5,6,2,2,6};
    cout<<has(a,8,2,2);
}
