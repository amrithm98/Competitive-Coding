#include<stack>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;


// int* stockSpan(int *price, int size) {
// 	// Write your code here
//     int *arr=new int[size];
//     vector<int> differences(size-1);
//     vector<int> min_just_before_i(size);
//     int span=1;    
//     for(int i=0;i<size-1;i++)
//     {
//         differences[i]=price[i+1]-price[i];
//         // cout<<differences[i]<<"\t";
//     }
//     cout<<"\n";
//     arr[0]=1;

//     int max_so_far=price[0];
//     int max_so_far_index=0;
//     int max_at_dip=INT8_MIN;
//     int max_count_dip=0;
//     for(int i=1;i<size;i++)
//     {
//         if(price[i]>max_so_far)
//         {
//             arr[i]=i+1;
//             max_so_far=price[i];
//             max_so_far_index=i;
//         }
//         else if(differences[i-1]>0 && price[max_so_far_index+1]<price[i])
//         {
//             arr[i]=i-max_so_far_index;
//         }
//         else if(differences[i-1]>0)
//         {
//             arr[i]=arr[i-1]+1;
//         }
//         else
//         {
//             arr[i]=1;
//         }
//     }
//     return arr;

// }

int* stockSpan(int *price, int size) {
    int *span=new int[size];
    span[0]=1;
    stack<int> priceStack;
    priceStack.push(0); 
    for(int i=1;i<size;i++)
    {
        while(!priceStack.empty() && price[priceStack.top()]<price[i])
            priceStack.pop();
        
        if(priceStack.empty())
            span[i]=i+1;
        else    
            span[i]=i-priceStack.top();
        
        priceStack.push(i);
    }
    return span;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *result;
    result=stockSpan(arr,n);
    for(int i=0;i<n;i++)
        cout<<result[i]<<" ";
}