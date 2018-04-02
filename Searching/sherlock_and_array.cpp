#include <bits/stdc++.h>

using namespace std;

string solve(vector < int > a){
    // Complete this function
    vector<int> prefSum(a.size()),suffSum(a.size());
    prefSum[0] = a[0];
    
    for(int i = 1; i < a.size(); i++)
        prefSum[i] = prefSum[i-1] + a[i];
    
    suffSum[a.size()-1] = a[a.size()-1];
    
    for(int i = a.size()-2; i >= 0; i--)
    {
        suffSum[i] = suffSum[i+1] + a[i];
    }
    
    for(int i = 0; i < a.size(); i++)
    {
        if(prefSum[i]-a[i] == suffSum[i]-a[i])
        {
            return "YES";
        }
    }
    
    return "NO";
}   

int main() 
{
    int T;
    cin >> T;
    
    for(int a0 = 0; a0 < T; a0++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = solve(a);
        cout << result << endl;
    }
    
    return 0;
}