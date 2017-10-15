#include <iostream>
using namespace std;


void placeNQueens(int n,string output=""){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  if(n==0)
  {
      cout<<output<<endl;
      return ;
  }
  

}



int main()
{
    int n;
    cin>>n;
    placeNQueens(n);
}