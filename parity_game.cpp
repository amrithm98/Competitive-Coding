#include <bits/stdc++.h>

using namespace std;

int smallestSizeSubsequence(int n, vector <int> A,int sum) {
    if(sum%2==0)
        return 0;
    else
    {
        int n_odd=0;
        int n_even=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]%2==0)
                n_even++;
            else
                n_odd++;
        }
        if(n_odd==1)
            return -1;
        else if(n_odd%2==1)
            return 1;
        else 
            return 0;
    }
    // Return the size of the smallest subsequence to remove
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    int sum=0;
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
       sum+=A[A_i];
    }
    int result = smallestSizeSubsequence(n, A,sum);
    cout << result << endl;
    return 0;
}
