#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long countCodes_iter(string s,int size)
{
    long long *output = new long long[size+1];
    output[0] = 1;
    output[1] = 1;
    for(int i = 2; i <= size ; i++)
    {
        if(s[i-1] == '0')
        {
            if(s[i-2]-'0' > 2)
            {
                output[size] = 0;
                break;
            }
            else if(s[i-2]-'0' == 0)
            {
                output[size] = 0;
                break;
            }
            else if(s[i-2] == '1' || s[i-2] =='2')
            {
                output[i-1] = output[i-2];
                output[i] = output[i-1];
                continue;
            }
        }
        output[i] = output[i-1]%MOD;
        if((s[i-2]-'0')*10+(s[i-1]-'0') <= 26 && s[i-2] !='0')
        {
            output[i] = (output[i] + output[i-2])%MOD;
        }
    }

    if(s[size-1] == '0')
    {
        if(s[size-2] > '2' || s[size-2] == '0')
        {
            output[size] = 0;
        }
    }
    // for(int i =0; i <=size ; i++)   
    //     cout<<output[i]<<" ";
    long long ans = output[size];
    delete [] output;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    while(s != "0")
    {
        cout<<countCodes_iter(s,s.size())<<endl;
        cin >> s;
    }
    return 0;
}