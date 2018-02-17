#include <bits/stdc++.h>
using namespace std;

void breakWords(char* S)
{
    int len = strlen(S);

    int count = 0;
    for(int i = len-1; i >= 0; i--)
    {
        if(arr[i] == ' ')
        {
            if(count % 2 != 0)
            {
                continue;
            }
            else
            {
                
            }
            count = 0;
        }
        else
            count++;
    }
}

int main()
{
    char input[10000];
    fgets(input,10000,stdin);
    breakWords(input);
    return 0;

}
