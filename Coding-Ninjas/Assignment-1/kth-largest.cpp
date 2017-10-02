#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
int kthLargest (vector<int> arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    sort(arr.begin(),arr.end());
    return arr[n-k];
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    cout<<kthLargest(arr,n,k)<<endl;
}

