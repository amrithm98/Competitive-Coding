#include <bits/stdc++.h>

using namespace std;

void swap(long* a, long* b)
{
    long t = *a;
    *a = *b;
    *b = t;
}

long partition (long arr[][2], long low, long high)
{
    long pivot = arr[high][0];
    long i = (low - 1); 
 
    for (long j = low; j <= high- 1; j++)
    {

        if (arr[j][0] <= pivot)
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

void quickSort(long arr[][2], long low, long high)
{
    if (low < high)
    {
        long pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

long buyMaximumProducts(long n, long k, long arr[][2]) 
{
    quickSort(arr,0,n-1);
    long bal=k,amt=0,count=0;
    for(long i=0;i<n && bal>=0;i++)
    {
        amt=arr[i][0]*arr[i][1];
        if(amt<=bal)
        {
            count+=arr[i][1];
        }
        else
        {
            count+=bal/arr[i][0];
            amt-=arr[i][0]*arr[i][1];
            amt+=count*arr[i][0];
        }
        bal-=amt;
    }
    return count;
}

int main() {
    long n;
    cin >> n;
    long arr[n][2];
    long m=0;
    for(long arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i][0];
       arr[arr_i][1]=++m;
    }
    long long k;
    cin >> k;
    long result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
    return 0;
}
