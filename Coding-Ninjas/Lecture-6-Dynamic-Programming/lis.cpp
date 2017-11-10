#include <iostream>
using namespace std;

int lis(int *input,int n)
{
    int *output = new int[n];
    output[0] = 1;
    for(int i = 1; i < n ; i++)
    {
        output[i] = 1;
        for(int j = i-1; j >= 0; j--)
        {
            if(input[j] > input[i])
                continue;
            else
            {
                int possAns = output[j] + 1;
                if(possAns > output[i])
                    output[i] = possAns;
            }
        }
    }
    int lis_len = 0;
    for(int i =0 ; i < n; i++)
        if(lis_len < output[i])
            lis_len = output[i];
    
    return lis_len;
}

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++)
        cin >> input[i];

    int len = lis(input,n);
    cout<<len<<endl;
    return 0;
}