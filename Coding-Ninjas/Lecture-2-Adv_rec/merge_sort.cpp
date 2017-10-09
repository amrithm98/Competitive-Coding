#include<iostream>
using namespace std;

void merge(int arr[],int l,int r, int m)
{
    int size_firstHalf=(m-l+1);
    int size_secondHalf=(r-m);

    int L[size_firstHalf];
    int R[size_secondHalf];

    for(int i=0;i<size_firstHalf;i++)
        L[i] = arr[l+i];

    for(int j=0;j<size_secondHalf;j++)
        R[j] = arr[m+1+j];
        
    int i=0,j=0,k=l;
    while(i<size_firstHalf && j<size_secondHalf)
    {
        if(L[i]<=R[j])
        {
            arr[k++]=L[i++];
        }   
        else 
        {
            arr[k++]=R[j++];
        }
    }
    while(i<size_firstHalf)
    {
        arr[k++]=L[i++];
    }
    while(j<size_secondHalf)
    {
        arr[k++]=R[j++];
    }
}

void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r-1)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,r,m);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    mergeSort(arr,0,n-1);

    cout<<"\nSorted Array: \n===============\n";
    for(int i=0;i<n;i++)
        cout << arr[i] <<" ";
    
}