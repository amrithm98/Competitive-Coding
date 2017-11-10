#include <bits/stdc++.h>
using namespace std;

int coin_change_naive(int n, int *d,int numD,int **output)
{
    if(n == 0)
    {
        return 1;
    }
    if(numD == 0)
    {
        return 0;
    }
    if(n < 0)
    {
        return 0;
    }
    if(output[n][numD] > -1)
    {
        return output[n][numD];
    }
    int first = coin_change_naive(n - d[0],d,numD,output);
    int second = coin_change_naive(n,d + 1,numD - 1,output);
    output[n][numD] = first + second;
    return output[n][numD];
}

int main()
{
    int n,d;
    cin >> d;   //Number of denom
    int *den = new int[d];

    for(int i = 0; i < d ; i++) 
        cin >> den[i];

    cin >> n;   //value

    int **output = new int*[n+1];
    for(int i = 0; i < n+1 ; i++)
    {
        output[i] = new int[d+1];
        for(int j = 0; j < d+1; j++)
            output[i][j] = -1;
    }
    cout<<coin_change_naive(n,den,d,output)<<endl;
    return 0;
}