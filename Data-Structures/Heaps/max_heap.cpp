#include <bits/stdc++.h>
using namespace std;

void max_heapify(int *arr,int i,int n)
{
    int left = 2*i;
    int right = 2*i+1;

    int largest;

    if(left <= n && arr[i] <arr[left])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if(right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        max_heapify(arr,largest,n);
    }
}

void buildMaxHeap(int *arr,int n)
{
    for(int i = n/2; i >= 1; i--)
    {
        max_heapify(arr,i,n);
    }
}

void printHeap(int *arr,int n)
{
    cout<<"\nHEAP\n";
    for(int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;

    cin >> n;

    int *arr = new int[n+1];

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    buildMaxHeap(arr,n);

    printHeap(arr,n);


}