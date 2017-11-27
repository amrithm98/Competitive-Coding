#include <bits/stdc++.h>
using namespace std;

int max_array(int *arr,int n,int *start,int *finish)
{
    int max_val = INT8_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max_val)
        {
            max_val = arr[i];
            *start = i;
            *finish = i;
        }
    }
    return max_val;
}

int kadanes_algo(int arr[],int *start,int *finish,int n)
{
    bool allNeg = true;

    for(int i = 0; i < n; i++)
        if(arr[i] > 0)
            allNeg = false;

    if(allNeg)
        return max_array(arr,n,start,finish);

    int current_max = 0,best_so_far = 0;
    int start_i = 0;
    for(int i = 0; i < n; i++)
    {
        current_max += arr[i];
        if(best_so_far < current_max)
        {
            best_so_far = current_max;
            *start = start_i;
            *finish = i;
        }
        if(current_max < 0)
        {
            current_max = 0;
            start_i = i+1;
        }
    }
    return best_so_far;
}

int maxSumRectangle(int **rectangle,int n,int m)
{
    int max_sum = INT8_MIN,left,right,top,bottom;
    int temp[n],sum,start = 0,finish = 0;
    int i,j;

    for(i = 0; i < m ; i++)
    {
        memset(temp,0,sizeof(temp));

        for(j = i; j < m; j++)
        {
            for(int k = 0; k < n ; k++)
                temp[k] += rectangle[k][j];   //Row Sum For Column(s) 

            /****
             * For Col 1,Col 1 + Col 2,Col 1+ Col 2 + Col 3
             *      Find Apt Top and Bottom Using Kadane's algo such that sum is maximum
             *      Taking n^2 combinations of L and R positions
             *      Input
             *      ======
             *      4 5 
             *      1 2 -1 -4 -20 
             *      -8 -3 4 2 1 
             *      3 8 10 1 3 
             *      -4 -1 1 7 -6
             *      Output
             *      =======
             *      for i = 0:
             *         j = 0 --> temp  = {1,-8,3,-4} MaxSum = 3 (2,0) --> (2,0)
             *         j = 1 --> temp  = {3,-11,11,-5} MaxSum = 11 (2,0) --> (2,1)
             *         j = 2 --> temp  = {2,-4,21,-4} MaxSum = 21 (2,0) --> (2,2)
             *         j = 3 --> temp  = {-2,-6,22,3} MaxSum = 25 (2,0) --> (3,3)
             *         j = 4 --> temp  = {-22,-7,6,-10} MaxSum = 6 (2,0) --> (2,4)
             *      for i = 1;
             *         j = 1 --> temp  = {2,-3,8,-1} MaxSum = 8 (2,1) --> (2,1)
             *         j = 2 --> temp  = {1,1,18,0} MaxSum = 20 (0,2) --> (3,2)
             *         j = 3 --> temp  = {-3,3,19,7} MaxSum = 29 (1,1) --> (3,3)    ******ANSWER******
             *         j = 4 --> temp  = {-23,4,22,1} MaxSum = 27 (1,1) --> (3,4)
             * 
             * */
            
            sum = kadanes_algo(temp,&start,&finish,n);

            if(sum > max_sum)
            {
                max_sum = sum;
                left = i;
                right = j;
                top = start;
                bottom = finish;
            }
        }
    }
    // cout<<"TOP: "<<left<<" "<<top<<endl;
    // cout<<"BOTTOM: "<<right<<" "<<bottom<<endl;
    return max_sum;
}

int main()
{
    int m,n;
    cin >> n >> m;
    int **mat = new int*[n];
    for(int i = 0; i < n; i++)
    {
        mat[i] = new int[m];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    cout<<maxSumRectangle(mat,n,m)<<endl;
    return 0;
}
