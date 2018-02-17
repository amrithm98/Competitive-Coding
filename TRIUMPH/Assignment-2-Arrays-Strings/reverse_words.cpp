#include <bits/stdc++.h>
using namespace std;

void reverseStringWordWise(char input[]) {
    // Write your code here
    int len = strlen(input);

    for(int i = 0; i < len/2; i++)
    {
       swap(input[i],input[len-i-1]);
    }    

    int start = 0;
    int i;
    
    for(i = 0; i < len; i++)
    {
        if(input[i] == ' ')
        {
            for(int j = 0; j < (i-start)/2; j++)
            {
                swap(input[start+j],input[i-j-1]);
            }
            start = i+1;
        }
    }
    for(int j = 0; j < (i-start)/2; j++)
    {
        swap(input[start+j],input[i-j-1]);
    }
}

int main()
{
    char input[1000];
    fgets(input,100,stdin); 

    reverseStringWordWise(input);
    for(int i = 0; input[i] != '\0'; i++)
        cout << input[i];
    
    return 0;
}