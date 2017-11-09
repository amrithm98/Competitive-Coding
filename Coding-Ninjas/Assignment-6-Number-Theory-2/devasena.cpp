#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define LL long long

long long modPower(long long a , long long b,long long MOD)
{
    if(b == 0)
        return 1;
    long long result = modPower(a,b/2,MOD);
    result = (result * result) % MOD;

    if(b%2 != 0)
        result = (result * a)%MOD;
    return result;
}

long long gcdProduct(vector<int> freq,int max_val)
{
    vector<int> subset(max_val+1,0);
  	long long MOD = 1000000007;
    long long result = 1;
    for(int i = max_val ; i >= 2 ; i--)
    {
        int currCount = freq[i];
        long long subsetCount = 0;
        for(int j = 2*i; j <= max_val; j += i)
        {
            currCount += freq[j];
            subsetCount =(subsetCount + subset[j])%(MOD-1);
        }
        long long subsets = ((MOD-1)+modPower(2,currCount,MOD-1)-1-subsetCount)%(MOD-1);
        subset[i] = subsets;
        result = (modPower(i,subsets,MOD) * result)%MOD;
    }
    return result;
}

int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> freq(MAX,0);
        int max_val = INT8_MIN;
        for(int i = 0 ; i < n; i++)
        {
            int a;
            cin >> a;   
            max_val = max(max_val,a);
            freq[a]++;         
        }
        cout<<gcdProduct(freq,max_val)<<endl;

    }
    return 0;
}