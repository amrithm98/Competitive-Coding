#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */   
  if(input[size-1]==x && size>0)
    return size-1;
  else if(size>0)
  {
      return lastIndex(input,size-1,x);
  }
  else
  {
      return -1;
  }
}

int main()
{
    int arr[]={2,3,4,5,7,7,8,8,8,7,7,8};
    cout<<lastIndex(arr,12,8)<<endl;
}