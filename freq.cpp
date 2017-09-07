#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

vector<int> frequency(string s) {
        vector<int> res(26);
        int len = s.size();
        int i = 0;
        while(i < len){
            int val = 0;
            if(i + 2 >= len || s[i + 2] != '#'){//single num
                val = s[i]- '0';
                res[val - 1]++;
                i++;
            }else if(s[i + 2] == '#'){//double num
                val = (s[i] - '0')*10 + (s[i + 1] - '0');
                res[val - 1]++;
                i = i + 3;
            }
            if(i < len){//update frequency
                 if(s[i] == '('){
                    int freq = s[i + 1] - '0';
                    res[val - 1] += freq - 1;
                    i = i + 3;
                }
            }
        }
        return res;
}
int main()
{
    string s[3]={"1(2)23(3)","1226#24#","23#(2)24#25#26#23#(3)"};
    for(int i=0;i<100;i++)
    {
        cout<<"\n";
        string a;
        cin>>a;
        vector<int> res=frequency(a);
        for(int j=0;j<26;j++)
            cout<<res[j]<<" ";
    }
}