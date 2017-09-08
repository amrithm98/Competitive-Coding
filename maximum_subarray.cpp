#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxVal(int a,int b)
{
    if(a>b)
        return a;
    else    
        return b;
}

int max_in_array(vector<int> array)
{
    int max=INT8_MIN;
    for(int i=0;i<array.size();i++)
    {
        if(array[i]>max)
            max=array[i];
    }
    return max;
}

int max_subarray(vector<int> array)
{
    int max=max_in_array(array);
    if(max<0)
        return max;
    
    int n=array.size();
    int max_so_far=0,max_end_here=0;
    for(int i=0;i<n;i++)
    {
        max_end_here=max_end_here+array[i];
        max_end_here=maxVal(max_end_here,0);
        max_so_far=maxVal(max_end_here,max_so_far);
    }
    return max_so_far;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    for(int t0=0;t0<t;t0++)
    {
        int n;
        cin>>n;
        vector<int> array(n);
        int i,j;
        int non_contiguos_sum=0;
        for(i=0;i<n;i++)
        {
            cin>>array[i];
            if(array[i]>0)
                non_contiguos_sum+=array[i];
        }
        if(non_contiguos_sum==0)
            non_contiguos_sum=max_in_array(array);
        cout<<max_subarray(array)<<" "<<non_contiguos_sum<<endl;
    }  
    return 0;
}
