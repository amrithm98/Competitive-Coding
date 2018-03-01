#include<bits/stdc++.h>
using namespace std;

int findAns(int *arr,int n,int *dp)
{
  
  	 if(n == 0 || n < 0)
     {
       return 0;
     }
  
  	 if(n == 1)
     {
        return arr[0];
     }
  
     if(dp[n] != -1)
       return dp[n];
  
  	 int ans1 = arr[0] + findAns(arr+2,n-2,dp);
     int ans2 = arr[1] + findAns(arr+3,n-3,dp);
  	 dp[n] = max(ans1,ans2);

  	 return dp[n];
}

int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
  	int *dp = new int[n+1];
  	for(int i = 0; i <= n; i++)
      	dp[i] = -1;
  
     return findAns(arr,n,dp);
     

}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << getMaxMoney(arr,n) << endl;
    return 0;
}