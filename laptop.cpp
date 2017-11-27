#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    vector<unordered_map<int,int>> countMap(n); 
    long long min = 1000000002;
    int pos = -1;

    for(int a0 = 0; a0 < n; a0++)
    {
        string s;
        long long price;
        cin >> s >> price;
        long long temp = price;

        names[a0] = s;

        while(temp != 0)
        {
            countMap[a0][temp%10]++;
            temp /= 10;
        }

        // for(auto it:countMap[a0])
        //     cout<<it.first<<" "<<it.second<<endl;

        if(countMap[a0][4] == countMap[a0][7] && countMap[a0][4] > 0)
        {
            int flag = 0;

            for(int i = 0 ; i <= 9; i++)
            {
                if(i ==4 || i == 7)
                {
                   continue;
                }
                else
                {
                     if(countMap[a0][i] > 0)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 0)
            {
                
                if(price < min)
                {
                    min = price;
                    pos = a0;
                }
            }
        }
    }
    if(pos != -1)
        cout<<names[pos]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
