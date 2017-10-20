#include <iostream>
using namespace std;

//Simply count the number of inversions

int merge(int arr[],int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1],R[n2];
    int i,j,k;

    for(i = 0;i < n1 ; i++)
        L[i] = arr[l+i];

    for(j = 0; j < n2; j++)
        R[j] = arr[m+j+1];

    int inversion_count = 0;
    i = 0,j = 0,k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            inversion_count += (n1-i);
            arr[k++] =  R[j++];
        }
    }

    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];

    return inversion_count;
}

int mergeSort(int arr[],int l,int r,int count = 0)
{
    if(l<r)
    {
        int m=(l+r-1)/2;
        int c1 = mergeSort(arr,l,m);
        int c2 = mergeSort(arr,m+1,r);
        count += merge(arr,l,m,r) + c1 + c2;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,i;
        cin >> n;

        int arr[n];

        for(i = 0;i < n;i++)
            cin >> arr[i];
        
        int inversions = mergeSort(arr,0,n-1);
        // cout<<inversions<<endl;
        if(inversions % 2 == 0)
            cout<<"YES"<<endl;

        else
            cout<<"NO"<<endl;

    }
    

}