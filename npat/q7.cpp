#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string input;
    vector<string> strs(1000);
    int size=0;
    while (getline(std::cin, input))
    {
        if (input.empty())
            break;
        strs[size]=(input);
        size++;
    }
    int n=size/2;
    for(int i=n;i<size;i++)
        cout<<strs[i]<<"\n";
    for(int i=0;i<n;i++)
        cout<<strs[i]<<"\n";
}