#include<iostream>
using namespace std;

void printSubsetSumToK(int input[], int size, int k,string output="") {
    // Write your code here
    if(size==0)
    {
        if(k==0)
        {
            cout<<output<<endl;
            return ;
        }
        return;
    }
    printSubsetSumToK(input+1,size-1,k,output);
    printSubsetSumToK(input+1,size-1,k-input[0],output+to_string(input[0])+" ");
}

int main()
{
    int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

    int k;
    cin>>k;

    printSubsetSumToK(arr,n,k);

}