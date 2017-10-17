#include<iostream>
#include<algorithm>
using namespace std;

long long merge(int arr[],int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1],R[n2];

    int i,j,k;

    for(i = 0;i<n1;i++)
        L[i]  =  arr[l+i];

    for(j = 0;j<n2;j++)
        R[j] = arr[m+1+j];

    i = 0,j = 0,k = l;

    long long sum = 0;

    while(i<n1 && j<n2)
    {
        if(L[i] < R[j])
        {
            sum += (L[i]*(n2-j));
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while(i<n1)
    {
        arr[k++] = L[i++]; 
    }

    while(j<n2) 
    {
        arr[k++] = R[j++];
    }

    return sum;
}

long long mergeSort(int arr[],int l,int r,long long sum=0)
{
    if(l<r)
    {
        int mid = (l+r-1)/2;
        long long c1 = mergeSort(arr,l,mid,sum);
        long long c2 = mergeSort(arr,mid+1,r,sum);
        sum += merge(arr,l,mid,r) + c1 + c2;
    }
    return sum;
}

long long solve(int A[], int n)
{

    long long sum = mergeSort(A,0,n-1);
    return sum;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for(int i = 0;i<n;i++)
            cin >> arr[i];

        cout<<solve(arr,n)<<endl;
    }
    

}