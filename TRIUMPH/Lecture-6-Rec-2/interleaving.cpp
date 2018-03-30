#include <bits/stdc++.h>
using namespace std;

void interleaving(char* first, char* second,string s = "") {
	// Write your code here
	if(first[0] == '\0' && second[0] == '\0')
    {
      	cout << s << endl;
      	return ;
    }

    if(first[0] != '\0')
    {
        interleaving(first+1,second,s + first[0]);
    }
    if(second[0] != '\0')
    {
        interleaving(first,second+1,s + second[0]);
    }
    
}

int main()
{
    char s[100],t[100];
    cin >> s >> t;

    interleaving(s,t);
    return 0;
}