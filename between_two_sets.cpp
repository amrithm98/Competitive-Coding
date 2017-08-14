#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long int ll;
int gcd(int a, int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

int findGCD(vector<int> arr, int n)
{
    int result = arr[0];
    for (int i=1; i<n; i++)
        result = gcd(arr[i], result);
 
    return result;
}

ll findlcm(vector<int> arr, int n)
{
    // Initialize result
    ll ans = arr[0];
    // ans contains LCM of arr[0],..arr[i]
    // after i'th iteration,
    for (int i=1; i<n; i++)
        ans = ( ((arr[i]*ans)) /
                (gcd(arr[i], ans)) );
    return ans;
}

int getTotalX(vector <int> a, vector <int> b) {
    ll lcm=findlcm(a,a.size());
    int gcf=findGCD(b,b.size());
    int finalCount=0;
    for(long i = lcm, j =2; i<=gcf; i=lcm*j,j++)
    {
            if(gcf%i==0)
            { 
                finalCount++;
            }
    }
    return finalCount;
    
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
