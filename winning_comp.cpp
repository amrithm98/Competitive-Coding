#include <bits/stdc++.h>

using namespace std;

long long int winningLotteryTicket(vector <string> tickets) {
    // Complete this function
    int n = tickets.size();
    
    int *arr = new int[1024];
    memset(arr,0,sizeof(arr));
    
    for(int i = 0; i < n; i++)
    {
        int bitConf = 0;
        for(int j = 0; j < tickets[i].size(); j++)
        {
            int num = tickets[i][j]-'0';
            bitConf |= (1 << num);
        }
        arr[bitConf]++;
    }
    
    long long int count = 0;
    // for(int i = 0; i < 1024; i++)
    // {
    //     if(arr[i] != 0)
    //     {
    //         cout << i << " " << arr[i] << endl;
    //     }
    // }
    vector<pair<int,int>> combo;
    
    for(int i = 0 ; i < 1024; i++)
    {
        for(int j = i+1; j < 1024; j++)
        {
            if( (i | j) == 1023)
            {
                combo.push_back(make_pair(i,j));
            }
        }
    }

    for(int i = 0; i < combo.size(); i++)
    {
        pair<int,int> c = combo[i];
        if(arr[c.first] != 0 && arr[c.second] != 0)
        {
            // cout << c.first << " " << c.second << endl;
            count += arr[c.first]*arr[c.second];
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<string> tickets(n);
    for(int tickets_i = 0; tickets_i < n; tickets_i++){
       cin >> tickets[tickets_i];
    }
    long long int result = winningLotteryTicket(tickets);
    cout << result << endl;
    return 0;
}
