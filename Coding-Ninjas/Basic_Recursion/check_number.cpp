#include<iostream>
using namespace std;

bool checkNumber(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  if(size==0)
    return false;
  if(input[0]==x)
    return true;
  else
    return checkNumber(input+1,size-1,x);

}

int main()
{
    int arr[]={2,4,5,6,7};
    cout<<checkNumber(arr,5,4)<<endl;
}