#include <bits/stdc++.h>

using namespace std;

int vect_diff(vector<int>a,vector<int>b);
int main() 
{
    vector<int> input(9);
    for(int i=0;i<9;i++)
        cin>>input[i];
    vector<vector<int>> magicSquares (8,vector<int>(9));
    magicSquares={{8,1,6,3,5,7,4,9,2},{4,9,2,3,5,7,8,1,6},{6,1,8,7,5,3,2,9,4},
                                    {2,9,4,7,5,3,6,1,8},{8,3,4,1,5,9,6,7,2},{6,7,2,1,5,9,8,3,4},
                                    {4,3,8,9,5,1,2,7,6},{2,7,6,9,5,1,4,3,8}};
    int diff=1000;
    for(int i=0;i<8;i++)
    {
        diff=min(diff,vect_diff(input,magicSquares[i]));
    }
    printf("%d\t",diff);
    return 0;
}
int vect_diff(vector<int> a,vector<int> b)
{
    vector<int> diff_vect(9);
    int sum=0;
    for(int i=0;i<9;i++)
    {
        diff_vect[i]=abs(a[i]-b[i]);
        sum+=diff_vect[i];
    }
    return sum;
    
}