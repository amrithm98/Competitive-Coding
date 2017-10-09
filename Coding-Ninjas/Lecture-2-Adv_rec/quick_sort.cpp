#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[],int start,int end)
{
    int pivot=arr[end];

    int i=start-1;
    int j=start;

    for(;j<end;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
    
}

void quickSort(int arr[],int start,int end)
{
    if(start<end)
    {
        int p=partition(arr,start,end);
        quickSort(arr,start,p-1);
        quickSort(arr,p+1,end);
    }
    else   
        return ;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    quickSort(arr,0,n-1);

    cout<<"\nSorted Array: \n=================\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}