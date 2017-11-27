#include <iostream>
using namespace std;

int min_cost(int **input,int si,int sj,int ei,int ej)
{
    if(si == ei && sj == ej)
    {
        return input[ei][ej];
    }
    if(si > ei || sj > ej)
    {
        return INT8_MAX;
    }
    int option1 = min_cost(input,si+1,sj,ei,ej);
    int option2 = min_cost(input,si+1,sj+1,ei,ej);
    int option3 = min_cost(input,si,sj+1,ei,ej);
    return input[si][sj] + min(option1,min(option2,option3));
}

int min_cost_dp(int **input,int n,int m)
{
    int **dp = new int*[n];
    for(int i = 0; i < n; i++)
        dp[i] = new int[m];
    
    //Init bottom most element
    dp[n-1][m-1] = input[n-1][m-1];

    //Init Last row and last column
    for(int i = n-2; i >= 0; i--)
        dp[i][m-1] = input[i][m-1] + dp[i+1][m-1]; //Sum of cell below and current input
    for(int j = m-2; j >= 0; j--)
        dp[n-1][j] = input[n-1][j] + dp[n-1][j+1];

    for(int i = n-2; i >= 0; i--)
    {
        for(int j = m-2 ; j >= 0; j--)
        {
            dp[i][j] = input[i][j] + min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]));
        }
    }

    return dp[0][0];
    
}

int main()
{
    int n,m;
    cin >> n >> m;
    int **input = new int*[n];
    for(int i = 0; i < n; i++)
        input[i] = new int[m];   

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> input[i][j];
        }
    }

    int result = min_cost_dp(input,n,m);
    cout<<result<<endl;
    //Delete
    return 0;

}