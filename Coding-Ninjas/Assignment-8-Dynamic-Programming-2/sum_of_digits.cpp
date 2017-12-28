#include <bits/stdc++.h>
using namespace std;

long long int sum = 0;

int numOfDigits(long long int n)
{
    int count = 0;
    while(n != 0)
    {   
        count++;
        n /= 10;
    }
    return count;
}

long long int sumOfDigits(long long int n)
{
    if(n < 10)
    {
        return n*(n+1)/2;
    }
    else
    {
        int d = numOfDigits(n) - 1;

        long long int *sums = new long long int[d];

        sums[0] = 0;
        sums[1] = 45;

        for(int i = 2; i <= d; i++)
            sums[i] = sums[i-1]*10 + 45*ceil(pow(10,i-1)); 
        
        int p = pow(10,d);
        int msd = n/p;

        long long ans = msd*sums[d] + (msd*(msd-1)/2)*p + msd*(1+ n%p);
        /***
         * For 3935
         * we have 3*sum(999) + (1+2)*1000 + 3*936 in the varible ans
         * Now we need to do it recursively for 935
         * 
         * 
         * */

        return ans + sumOfDigits(n%p);
    }
}

int main()
{
    long long int a,b;
    cin >> a >> b;


    while(a != -1 && b != -1)
    {   
        long long int ans1 = sumOfDigits(a-1);

        long long int ans2 = sumOfDigits(b);

        cout<<ans2 - ans1<<endl;

        cin >> a >> b;
    }

    return 0;
}
