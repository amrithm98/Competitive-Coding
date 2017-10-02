#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

/***
 * For each element in array
 *      see if it has no element less than it with a difference of 1. i.e. a[i]-1 doesn't exist in the map
 *      if a[i]-1 doesnt exist...increment a[i] till that element is not present in the map
 *      keep two variables to store an a[i] and number of consecutive elements 
 *      update n_elements and start_element whenever a longer consecutive sequence is seen
 **/

vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
    unordered_map<int,int> countMap;
    vector<int> results;

    for(int i=0;i<n;i++)
    {
        countMap[arr[i]]++;
    }

    int start_element=0,n_elements=0;

    for(int i=0;i<n;i++)
    {
        if(countMap.find(arr[i]-1)==countMap.end())
        {
            int next_consecutive_element=arr[i];
            while(countMap.find(next_consecutive_element)!=countMap.end())
                next_consecutive_element++;

            if(n_elements<next_consecutive_element-arr[i])
            {
                n_elements=next_consecutive_element-arr[i];
                start_element=arr[i];
            }

        }
    }

    for(int i=start_element;i<start_element+n_elements;i++)
        results.push_back(i);
    return results;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> res;
    res=longestSubsequence(arr,n);
    for(auto it:res)
        cout<<it<<"\n";
}