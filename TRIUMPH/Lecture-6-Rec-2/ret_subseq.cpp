#include <bits/stdc++.h>
using namespace std;


int subseq(string input,string *output)
{
    if(input.empty())
    {
        output[0] = "";
        return 1;
    }
    int k = subseq(input.substr(1),output);
    for(int i = 0; i < k; i++)
    {
        output[i+k] = input[0] + output[i];
    }
    return 2*k;
}

int main()
{
    string s;
    cin >> s;

    string *output = new string[1<<s.size()];
    int cnt = subseq(s,output);
    for(int i = 0; i < cnt; i++)
        cout << output[i] << endl;

    return 0;
}