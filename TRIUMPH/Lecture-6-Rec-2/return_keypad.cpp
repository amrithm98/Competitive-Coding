#include <bits/stdc++.h>
using namespace std;

unordered_map<int,string> keys;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0)
    {
        output[0] = "";
        return 1;
    }

    int quo = num/10;
    int rem = num%10;

    int smallOutput = keypad(quo,output);
    
    for(int i = 0; i < smallOutput; i++)
    {
        string temp = output[i];
        for(int j = 0; j < keys[rem].size(); j++)
        {
            output[smallOutput*j + i] = temp + keys[rem][j];
        }
    }
    return keys[rem].size()*smallOutput;
}

int main()
{
    keys[2] = "abc";
    keys[3] = "def";
    keys[4] = "ghi";
    keys[5] = "jkl";
    keys[6] = "mno";
    keys[7] = "pqrs";
    keys[8] = "tuv";
    keys[9] = "wxyz";

    int n;
    cin >> n;

    string *output = new string[1000];
    int size = keypad(n,output);
    for(int i = 0; i < size; i++)
        cout << output[i] << endl;

    return 0;
}
