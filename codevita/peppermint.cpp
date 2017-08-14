#include<iostream>
#include <bits/stdc++.h>
int main()
{
    long q;
    std::cin >> q;
    long arr[q];
    for(long a0 = 0; a0 < q; a0++){
        long sweet;
        long wrap;
        long k;
        std::cin >>sweet>>wrap>>k;
        long wrappers=sweet+wrap;
        while(wrappers>=k){
            long temp=wrappers/k;
            wrappers=temp+(wrappers%k);
            sweet+=temp;
        }
        arr[a0]=sweet;
    }
    for(long i=0;i<q;i++)
    {
        std::cout<<arr[i]<<"\n";
    }
    return 0;
}