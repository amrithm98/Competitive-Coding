#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> calories(n);
    for(int calories_i = 0; calories_i < n; calories_i++){
       cin >> calories[calories_i];
    }
    sort(calories.begin(),calories.end());
    long miles=0;
    int k=0;
    for(int i=calories.size()-1;i>=0;i--)
    {
        miles+=pow(2,k)*calories[i];
        k++;
    }
    cout<<miles;
    // your code goes here
    return 0;
}
