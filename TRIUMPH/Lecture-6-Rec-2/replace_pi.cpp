// Change in the given string itself. So no need to return or print anything
#include <bits/stdc++.h>
using namespace std;


void replacePi(char input[]) {
	// Write your code here
	if(input[0] == '\0')
    {
      	return;
    }
  	if(input[1] != '\0')
    {
      	if(input[0] == 'p' && input[1] == 'i')
        {
            int i;
          	input[0] = '3';
          	input[1] = '.';
          	int len = strlen(input);
          	for(i = len -1; i >= 0; i--)
              	input[i+2] = input[i];
          	input[len+2] = '\0';
          	input[2] = '1';
          	input[3] = '4';
          	replacePi(input);
        }
      	else
          replacePi(input+1);
    }
}


int main()
{
    char input[100];
    cin >> input;

    replacePi(input);
    cout << input << endl;

    return 0;
}