#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 1000001

vector<long long> factorialMod(MAX);

long long modPower(long long a,long long b)
{
    if(b == 0)
        return 1;

    long long result = modPower(a,b/2);

    result = (result * result )%MOD;

    if(b%2 != 0)
        result = (result * a)%MOD;      //Didn't need a%MOD it gave wrong
    return result;
}

void nFactModM()
{
    long long ans = 1;
    factorialMod[0] = 1;
    for(int i = 1; i < MAX ; i++)
    {
        ans = (ans*i)%MOD;
        factorialMod[i] = ans;
    }
}

int main() {

	// Write your code here
    nFactModM();
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        long long answer = modPower(2,k);
        answer = (answer * factorialMod[n])%MOD;
        answer = (answer * modPower(factorialMod[n-k],MOD-2))%MOD;
        answer = (answer * modPower(factorialMod[k],MOD-2))%MOD;
        cout<<answer<<endl;
    }
    return 0;
}