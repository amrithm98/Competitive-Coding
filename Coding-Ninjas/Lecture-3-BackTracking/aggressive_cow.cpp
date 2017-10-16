#include<bits/stdc++.h>
using namespace std;

void merge(vector<long long> &arr,long long l,long long m,long long r)
{
    long long n1=m-l+1;
    long long n2=r-m;

    vector<long long> L(n1);
    vector<long long> R(n2);

    for(long long i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }

    for(long long i=0;i<n2;i++)
    {
        R[i]=arr[m+1+i];
    }

    long long i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }

    while(i<n1)
    {
        arr[k++]=L[i++];
    }
    while(j<n2)
    {
        arr[k++]=R[j++];
    }
}

void mergeSort(vector<long long> &arr,long long l,long long r)
{
    if(l<r)
    {
        long long m=(l+r-1)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

bool checkPlacable(vector<long long> xi,long long n,long long c,long long d)
{
    long long count=1;
    long long currPlaced=xi[0];
    for(long long i=1;i<n;i++)
    {
        if(xi[i]-currPlaced>=d)
        {
            count++;
            currPlaced=xi[i];
        }
    }
    if(count>=c)
        return true;
    else
        return false;
}

long long binarySearch(vector<long long> xi,long long start,long long end,long long c)
{
    long long mid=(start+end)/2;
    if(start>end)
    {
        return mid;
    }
    if(checkPlacable(xi,xi.size(),c,mid))
    {
        return binarySearch(xi,mid+1,end,c);
    }
    else
    {
        return binarySearch(xi,start,mid-1,c);
    }
}

long long printMinimumDistance(vector<long long> &xi,long long n,long long c)
{
    //Merge Sort increased the complexity
    // mergeSort(xi,0,n-1);

    sort(xi.begin(),xi.end());

    long long maxDiff=xi[n-1]-xi[0];
        
    long long beg=0,end=maxDiff;

    long long ans=-1;
    
    while(beg<=end)
    {
        long long mid=(beg+end)/2;
        if(checkPlacable(xi,n,c,mid))
        {
            ans=mid;
            beg=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }

    return ans;
}

int main() {

	// Write your code here
    long long t;
    cin>>t;
    
    for(long long t0=0;t0<t;t0++)
    {
        long long n,c,i;
        cin>>n>>c;
        
        vector<long long> xi(n);

        for(i=0;i<n;i++)
            cin>>xi[i];

        cout<<printMinimumDistance(xi,n,c)<<endl;
    }
}