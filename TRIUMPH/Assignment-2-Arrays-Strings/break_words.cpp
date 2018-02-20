#include <bits/stdc++.h>
using namespace std;

void breakWords(char* S)
{
    int len = strlen(S)-1;
    int count = 0;

    for(int i = len-1; i >= 0; i--)
    {
        // cout << i << " : " << count << endl;
        if(S[i] == ' ')
        {
            if(count % 2 != 0)
            {
                count = 0;
                continue;
            }
            else
            {
                if(count >= 4)
                {
                    int start = (2 + i + count/2);
                    int j;
                    for( j = len; j >= start; j--)
                    {
                        S[j] = S[j-1];
                    }
                    S[j] = ' ';
                    S[len+1] = '\0';
                    len++;
                }
            }
            count = 0;
        }
        else
            count++;
    }
    if(count % 2 == 0 && count >= 4)
    {
        int start = (1 + count/2);
        int j;
        for( j = len; j >= start; j--)
        {
            S[j] = S[j-1];
        }
        S[j] = ' ';
        S[len+1] = '\0';
        len++;
    }

    for(int i = 0; i < len; i++)
        cout << S[i];

}

int main()
{
    char input[10000];
    fgets(input,10000,stdin);
    breakWords(input);
    return 0;

}
