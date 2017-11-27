#include <bits/stdc++.h>

using namespace std;

// long long surfaceArea(vector < vector<int> > A,int h,int w) {
//     // Complete this function
//     long long area = 2*h*w; 
//     for(int i = 0; i < h; i++)
//     {
//         long long rowSum = 0;
//         for(int j = 0; j < w; j++)
//         {
//             if(A[i][j] > rowSum )
//                 rowSum = A[i][j];
//         }
//         area += (rowSum*2);
//     }

//     for(int i = 0; i < w; i++)
//     {
//         long long rowSum = 0;
//         for(int j = 0; j < h; j++)
//         {
//             if(A[j][i] > rowSum )
//                 rowSum = A[j][i];
//         }
//         area += (rowSum*2);
//     }

//     for(int i = 0; i < h; i++)
//     {
//         long long inBetween = 0;
//         for(int j = 1; j < w-1; j++)
//         {
            
//             if(A[i][j-1] > A[i][j] && A[i][j] < A[i][j+1])
//             {
//                 // cout<<A[i][j-1]<<" "<<A[i][j]<<" "<<A[i][j+1]<<endl;   
//                 int min_val = min(A[i][j-1],A[i][j+1]);             
//                 inBetween += (abs(min_val - A[i][j]) * 2);
//             }
//         }
//         // cout<<inBetween<<endl;
//         area += (inBetween);
//     }

//     for(int i = 0; i < w ; i++)
//     {
//         long long inBetween = 0;
//         for(int j = 1; j < h-1; j++)
//         {
//             if(A[j][i] < A[j-1][i] && A[j][i] < A[j+1][i])
//             {
//                 int min_val = min(A[j+1][i],A[j-1][i]);
//                 inBetween += (abs(min_val - A[j][i])*2);
//             }
//         }
//         // cout<<inBetween<<endl;
//         area += (inBetween);
//     }

//     return area;
// }
long surfaceArea(vector < vector<int> > A,int h,int w) 
{
    // Complete this function
    long sum = 2*h*w;
    for(int i = 0; i < h; i++)
    {
        sum += (A[i][0]+A[i][w-1]);
        for(int j = 1; j < w ; j++)
        {
            sum += abs(A[i][j] - A[i][j-1]);
        }
        // cout<<sum<<endl;
    }

    for(int i = 0; i < w; i++)
    {
        sum += (A[0][i]+A[h-1][i]);
        for(int j = 1; j < h ; j++)
        {
            sum += abs(A[j][i] - A[j-1][i]);
        }
        // cout<<sum<<endl;
    }

    return sum;
}

int main() {
    int H;
    int W;
    cin >> H >> W;
    vector< vector<int> > A(H,vector<int>(W));
    for(int A_i = 0;A_i < H;A_i++){
       for(int A_j = 0;A_j < W;A_j++){
          cin >> A[A_i][A_j];
       }
    }
    if(H == 1 && W == 1)
        cout<<A[0][0]*6<<endl;
    else
    {
        long long result = surfaceArea(A,H,W);
        cout << result << endl;
    }
    
    return 0;
}
