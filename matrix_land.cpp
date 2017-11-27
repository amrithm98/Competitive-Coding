#include <bits/stdc++.h>

using namespace std;

void kadanes(vector<int> &arr)
{    
    int max_curr = arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i-1] > 0)  
            arr[i] += arr[i-1];
        if(arr[i] >= max_curr)
            max_curr = arr[i];
    }
}

long long matrixLand(vector < vector<int> > A,int n,int m) {
    // Complete this function
    for(int i = 0; i < A.size(); i++)
        kadanes(A[i]);

    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j <A[i].size(); j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int **dp = new int*[n];
    for(int i = 0; i < n; i++)
        dp[i] = new int[m];

    dp[n-1][m-1] = A[n-1][m-1];

    for(int i = m-2 ; i >= 0 ; i--)
    {
        if(A[n-1][i] < 0 && A[n-1][i+1] > 0)
            A[n-1][i] += A[n-1][i+1];
        else if(A[n-1][i+1] > 0)
            A[n-1][i] = max(A[n-1][i+1] , A[n-1][i]);
        dp[n-1][i] = A[n-1][i];
    }
   
    for(int i =n-2; i >= 0; i--)
    {
        dp[i][m-1] = A[i][m-1] + dp[i+1][n-1];
    }

    for(int i = n-2 ; i >= 0 ; i--)
    {
        for(int j = m-2; j>=0 ; j--)
        {
            if(A[i][j+1] > 0)
            { 
                if(A[i][j] < 0)
                    A[i][j] += A[i][j+1];
                else
                    A[i][j] = max(A[i][j+1] , A[i][j]);
            }
            dp[i][j] = A[i][j] + dp[i+1][j];
        }
    }

    for(int i = 0; i < n; i++)
    {   
        for(int j = 0; j < m; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    int result = dp[0][0];
    for(int i = 1; i<m ; i++)
    {
        result = max(result , dp[0][i]);
    }
    return result;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector< vector<int> > A(n,vector<int>(m));
    vector<bool> allNeg(n);
    bool allneg = true;
    for(int A_i = 0;A_i < n;A_i++){
       allneg = true;
       for(int A_j = 0;A_j < m;A_j++){
          cin >> A[A_i][A_j];
          if(A[A_i][A_j] > 0)
              allneg = false;
       }
       allNeg[A_i] = allneg;
    }
    long long result = matrixLand(A,n,m);
    cout << result << endl;
    return 0;;
}
