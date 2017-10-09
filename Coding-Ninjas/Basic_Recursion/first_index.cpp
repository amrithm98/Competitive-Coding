#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */   
  static int count=1;
  if(input[0]==x && size>0)
    return 0;
  else if(size>0)
  {
      count++;
      return 1+firstIndex(input+1,size-1,x);
  }
  else if(size==0)
  {
      return -1*count;
  }

}

int main()
{
    int arr[]={2,3,4,5,7,7,8};
    cout<<firstIndex(arr,7,7)<<endl;
}