#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int> arr,int n)
{
    int max_end_here=1,max_so_far=1,min_end_here=1;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            max_end_here=max_end_here*arr[i];
            min_end_here=min(min_end_here*arr[i],1);
        }
        else if(arr[i]==0)
        {
            max_end_here=1;
            min_end_here=1;
        }
        else
        {
            int temp=max_end_here;
            max_end_here=max(min_end_here*arr[i],1);
            min_end_here=temp*arr[i];
        }
        if(max_so_far<max_end_here)
            max_so_far=max_end_here;
    }
    return max_so_far;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"\n"<<maxProduct(arr,n);
}