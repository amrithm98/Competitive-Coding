#include <bits/stdc++.h>
#include <map>
using namespace std;

int gemstones(vector <string> arr){
    // Complete this function
    map<char,int> tot_char;
    map<char,int> charMap[arr.size()];
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            tot_char[arr[i][j]]++;
            charMap[i][arr[i][j]]++;
        }
    }
    int count=0;
    for(auto it:tot_char)
    {
        int flag=0;
        for(int i=0;i<arr.size();i++)
        {
            if(charMap[i][it.first]==0)
                flag=1;
        }
        if(flag==0)
            count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = gemstones(arr);
    cout << result << endl;
    return 0;
}
