#include <bits/stdc++.h>
using namespace std;

void findLargestUniqueSubstring(char input[], char output[])
{
	// Write your code here
    int *arr = new int[26];
    for(int i = 0; i < 26; i++)
        arr[i] = -1;

    int prev_index = -1;
    int curr_len = 0;
    int max_len = 1;
    int max_index = 0;

    for(int i = 0; input[i] != '\0'; i++)
    {
        prev_index = arr[input[i]-'a'];

        if(prev_index == -1 || i - curr_len > prev_index)
        {
            curr_len++;
        }
        else
        {
            // cout << "\nANS: : " << input[i] << " " << curr_len << endl;
            if(curr_len > max_len)
            {
                max_len = curr_len;
                max_index = (i-curr_len);
            }
            curr_len = i-prev_index;
        }

        arr[input[i]-'a'] = i;
    }
    for(int i = 0; i < max_len; i++)
        output[i] = input[i + max_index];
    output[max_len] = '\0';
}

int main()
{
    char input[10000],output[10000];
    fgets(input,10000,stdin);

    findLargestUniqueSubstring(input,output);
    return 0;
}