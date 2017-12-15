#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000000
#define MAX 40

vector<long long> factorialMod(MAX);

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

void printFactorial(vector<long> &A,int l,int r)
{
    long long ans = 0;
    for(int i = l; i <= r; i++)
    {
        // cout<<"\nFac: "<<A[i]<<endl;
        if(A[i] >= 40)
            continue;
        ans = ((ans % MOD) + (factorialMod[A[i]])%MOD)%MOD;
    }
    cout<<ans<<endl;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> A(n);
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    nFactModM();
    // cout<<factorialMod[15]+12+4<<endl;
    int buffer = 0;
    for(int a0 = 0; a0 < m; a0++){
        // Write Your Code Here
        int a,b,c;
        cin >> a >> b >> c;
        b--;
        c--;
        
        switch(a)
        {
            case 1:
                for(int i = b; i <= c; i++)
                    A[i]++;
                break;
            case 2:
                printFactorial(A,b,c);
                break;
            case 3:
                // cout<<b<<" "<<c;
                A[b] = c+1;
                break;
        }
        // for(int i = b; i <= c; i++)
        //             cout<<A[i]<<" ";
    }
    return 0;
}
