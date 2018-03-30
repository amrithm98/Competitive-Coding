#include <bits/stdc++.h>
using namespace std;

int minCount(int n){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
  	if(n < 0)
    {
      	return INT_MAX;
    }
  	if(n == 0)
    {
      	return 0;
    }
  
  	int m_c = INT_MAX;
  	for(int i = 1; i*i <= n; i++)
    {
      	m_c = min(m_c,1 + minCount(n - i*i));
    }
  
  	return m_c;
}

int main()
{
    int n;
    cin >> n;

    cout << minCount(n << endl;

    return 0;
}