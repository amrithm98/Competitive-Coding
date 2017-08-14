#include <iostream>

using namespace std;

int checkAddSeq(int *x, int *y, int n) {
  for(int i = 0; i < n; i++) {
      int m=0,temp=0;
      while(m<=i)
      {
        temp+=x[m];
        m++;
      }
      if(y[i]!=temp)
      {
          return 0;
      }

  }
  return 1;
}
int main()
{
    int a[]={1,2,5,4,3};
    int b[]={1,3,8,12,15};
    cout<<checkAddSeq(a,b,5);
}