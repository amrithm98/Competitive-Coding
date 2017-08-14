#include<iostream>
#include<string>
long long fact(int n)
{
    if(n==0)
        return 0;
    else
    {
        long long fact=1;
        for(long long i=1;i<=n;i++)
            fact=fact*i;
        return fact;
    }
}
long getNumFromRank(long n){
    std::string permNum="";
    int len=10;
    int perm[]={0,1,2,3,4,5,6,7,8,9};
    long remain=n-1;
   
    for(int i=1;i<=10;i++)
    {
        long j=remain/fact(10-i);
        remain=remain%fact(10-i);
        permNum+=std::to_string(perm[j]);
        for (long k = j; k < 10; ++k)
        {
            perm[k] = perm[k + 1];
        }
        len--;
        if(remain==0)
            break;
    }
    for(int i=0;i<len;i++)
        permNum+=std::to_string(perm[i]);
    return std::atol(permNum.c_str());

}
int main()
{
    long n;
    std::cin>>n;
    long *arr=new long[n];
    for(int i=0;i<n;i++)
        std::cin>>arr[i];
    long s=0;
    for(int i=0;i<n;i++)
    {
        long num=getNumFromRank(arr[i]);
        s+=num;
    }
    cout<<s;
}