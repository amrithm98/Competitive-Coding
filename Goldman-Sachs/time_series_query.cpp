#include <bits/stdc++.h>

using namespace std;

void copy(long new_array[][2],long old_array[][2],long n)
{
    for(long i=0;i<n;i++)
    {
        new_array[i][0]=old_array[i][0];
        new_array[i][1]=old_array[i][1];
    }
}

long query_1(long arr[][2],long n,long v)
{   
    long val=0;
    for(long i=0;i<n;i++)
    {
        if(arr[i][1]>=v)
        {
            val=arr[i][0];
            break;
        }
    }
    if(val==0)
        return -1;
    return val;
}

long query_2(long arr[][2],long n,long v)
{
    long val=0,pos=0,i,j;
    for(i=0;i<n;i++)
    {
        if(arr[i][0]>=v)
        {
            break;
        }
    }
    if(i==n)
        return -1;
    long max=0;
    for(j=i;j<n;j++)
    {
        if(arr[j][1]>max)
        {
            max=arr[j][1];
        }
    }
    if(max==0)
        return -1;
    return max;
}

int main() 
{
    long n;
    long q;
    cin >> n >> q;
    long arr[n][2];

    for(long t_i = 0; t_i < n; t_i++){
        cin >> arr[t_i][0];
    }

    for(long p_i = 0; p_i < n; p_i++){
       cin >> arr[p_i][1];
    }

    long time_sorted[n][2];
    copy(time_sorted,arr,n);
    
    for(long a0 = 0; a0 < q; a0++){
        long _type;
        long v;
        long result;
        cin >> _type >> v;
        if(_type==1)
        {
             result=query_1(time_sorted,n,v);
             cout<<result<<endl;
        }
        else   
        {
             result=query_2(time_sorted,n,v);
             cout<<result<<endl;
        }
    }
    return 0;
}
