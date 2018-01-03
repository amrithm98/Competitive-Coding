#include <bits/stdc++.h>

using namespace std;

int digSum(int n)
{
    int ans = 0;
    while(n != 0)
    {
        ans += n%10;
        n/= 10;
    }
    return ans;
}
string canConstruct(vector <int> a) 
{
    // Return "Yes" or "No" denoting whether you can construct the required number.
    long long int sum = 0;
    for(int i = 0; i < a.size(); i++)
    {
        sum += digSum(a[i]);
    }
    if(sum % 3 == 0)
    {
        return "Yes";
    }
    else
        return "No";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = canConstruct(a);
        cout << result << endl;
    }
    return 0;
}
