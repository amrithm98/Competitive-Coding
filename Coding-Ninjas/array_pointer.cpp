#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    int *p;

    p=arr;

    arr[0]=5;
    arr[1]=10;

    cout<<"Both Points to same address"<<endl;
    cout<<arr<<endl;
    cout<<p<<endl;
    
    cout<<"\nAddress of Pointer and address of array_base are different"<<endl;
    cout<<&p<<endl;
    cout<<&arr<<endl;

    cout<<"\nAnother method of Array Indexing 1[arr]"<<endl;
    cout<<1[arr]<<endl;

    cout<<"\nDifference in sizeof()"<<endl;
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(p)<<endl;

    cout<<"\nYou cant Do arr=arr+3 unlike p=p+3.. Array relocation is not possible";

    cout<<"\nREASON: Array base is not stored in a pointer variable of 8 byte size. It's different";

}