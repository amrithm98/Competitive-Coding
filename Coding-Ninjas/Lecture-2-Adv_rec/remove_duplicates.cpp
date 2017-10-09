#include<iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
    if(input[0]=='\0')
        return;
    else
    {
        if(input[1]!='\0')
        {
            if(input[0]==input[1])
            {
                int i=1;
                for(;input[i]!='\0';i++)
                    input[i-1]=input[i];
                input[i-1]=input[i];
                removeConsecutiveDuplicates(input);
            }
            else
            {
                removeConsecutiveDuplicates(input+1);
            }
        }
        else
            return;
    }

}

int main()
{
    char input[100];
    cin>>input;
    removeConsecutiveDuplicates(input);
    cout<<input;
}