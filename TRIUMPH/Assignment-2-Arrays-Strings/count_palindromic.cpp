#include <bits/stdc++.h>
using namespace std;

int countPalindromeSubstrings(char s[]) {
    
    int len = 0;
    for(; s[len] != '\0'; len++);

    //Counting all single Chars
    int count = len;

    //Odd length substring
    for(int i = 0; i < len; i++)
    {
        int mid = i;
        int left = mid - 1;
        int right = mid + 1;
        //Taking each character as mid and then checking left and right. 
        while(left >= 0 && right < len)
        {
            if(s[left] == s[right])
            {
                count++;
                left--;
                right++;
                // cout << "\nCOUNTING: " << count;
            }
            else
            {
                break;
            }
        }
    }
    //Even length Substring
    for(int i = 0; i < len-1; i++)
    {
        int mid1 = i;
        int mid2 = i+1;
        if(s[mid1] == s[mid2])
        {
            //if bb is found. Inc by 1
            count++;
            int left = mid1 - 1;
            int right = mid2 + 1;
            //Doing the same checking by taking two adjacent equal elements
            while(left >= 0 && right < len)
            {
                if(s[left] == s[right])
                {
                    // cout << "\nEVEN COUNTING: ";
                    count++;
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            continue;
        }
    }
    return count;
}

int main()
{
    char input[10000],output[10000];
    fgets(input,10000,stdin);

    cout << countPalindromeSubstrings(input);
    return 0;
}