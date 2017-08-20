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

void swap(long* a, long* b)
{
    long t = *a;
    *a = *b;
    *b = t;
}

long partition (long arr[][2], long low, long high,long place)
{
    long pivot = arr[high][place];
    long i = (low - 1); 
 
    for (long j = low; j <= high- 1; j++)
    {

        if (arr[j][place] <= pivot)
        {
            i++;
            swap(&arr[i][0], &arr[j][0]);
            swap(&arr[i][1], &arr[j][1]);
        }
    }
    swap(&arr[i + 1][0], &arr[high][0]);
    swap(&arr[i + 1][1], &arr[high][1]);
    return (i + 1);
}

void merge(long arr[][2], long l, long m, long r)
{
    long i, j, k;
    long n1 = m - l + 1;
    long n2 =  r - m;
 
    /* create temp arrays */
    long L[n1][2], R[n2][2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    for (j = 0; j < n2; j++)
    {
        R[j][0] = arr[m + 1+ j][0];   
        R[j][1] = arr[m + 1+ j][1];      
    }
        
 
    /* Merge the temp arrays back longo arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i][0] <= R[j][0])
        {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
}


void mergeSort(long arr[][2], long l, long r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

void quickSort(long arr[][2], long low, long high,long place)
{
    if (low < high)
    {
        long pi = partition(arr, low, high,place);
        quickSort(arr, low, pi - 1,place);
        quickSort(arr, pi + 1, high,place);
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

    for(long t_i = 0; t_i < 2*n; t_i++){
       if(t_i>=n)
            cin>>arr[t_i-n][1];
        else    
            cin >> arr[t_i][0];
    }

    // for(long p_i = 0; p_i < n; p_i++){
    //    cin >> arr[p_i][1];
    // }

    long time_sorted[n][2];
    // long price_sorted[n][2];
    copy(time_sorted,arr,n);
    // copy(price_sorted,arr,n);
    
    // mergeSort(time_sorted,0,n-1);
    // quickSort(price_sorted,0,n-1,1);

    // cout<<"\nTime Sorted:\n";
    // for(long i=0;i<n;i++)
    // {
    //     cout<<time_sorted[i][0]<<" "<<time_sorted[i][1]<<"\n";
    // }

    // cout<<"\nPRice Sorted:\n";
    // for(long i=0;i<n;i++)
    // {
    //     cout<<price_sorted[i][0]<<" "<<price_sorted[i][1]<<"\n";
    // }
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
