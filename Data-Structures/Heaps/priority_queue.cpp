#include <bits/stdc++.h>
using namespace std;

void printHeap(int *arr,int n)
{
    cout<<"\nQUEUE: ";
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}

void max_heapify(int *arr,int i,int n)
{
    int left = 2*i;
    int right = 2*i+1;

    int largest;

    if(left <= n && arr[left] > arr[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if(right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        max_heapify(arr,largest,n);
    }
}

int extractMax(int *arr,int *length)
{
    if(length == 0)
    {
        cout<<"\nQUEUE EMPTY";
        return 0;
    }

    int root = arr[1];

    arr[1] = arr[*length];

    *length = *length - 1;

    max_heapify(arr,1,*length);

    return root;

}

void increaseVal(int *arr,int i,int val)
{
    if(val < arr[i])
    {
        cout<<"\nAlready Low Priority";
        return;
    }

    arr[i] = val;

    while( i > 1 && arr[i/2] < arr[i])
    {
        swap(arr[i/2],arr[i]);
        i = i/2;
    }
    

}

void insertVal(int *arr,int *length,int val)
{

    *length = *length + 1;
    arr[*length] = -1;
    increaseVal(arr,*length,val);
}

int main()
{
    int *arr = new int[100001];
    int length = 0;
    while(1)
    {
        int ch,pri,root;

        cout<<"\nPRIORITY QUEUE: \n==================\n";
        cout<<"\n1. Insert";
        cout<<"\n2. Remove Max";
        cout<<"\n3. View";
        cout<<"\nEnter Choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                cout << "\nEnter Priority: ";
                cin >> pri;
                insertVal(arr,&length,pri);
                cout<<"\nLENGTH : "<<length;
                break;
            case 2:
                root = extractMax(arr,&length);
                cout<<"\nMAXIMUM Priority Element: "<<root<<endl;
                break;
            case 3:
                printHeap(arr,length);
                break;
        }
    }
}