#include<iostream>

using namespace std;
int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  if(n==1)
  {
      return input[0];
  }
  else
  {
      int sumC=sum(input+1,n-1);
      return sumC+input[0];
  }

}

int main()
{
    int n,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<sum(arr,n)<<endl;
}