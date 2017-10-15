#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void printPermutations(string input,string output=""){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input=="")
    {
        cout<<output<<endl;
        return;
    }
    for(int i=0;i<input.size();i++)
    {
        printPermutations(input.substr(1),output+input[0]);
        rotate(input.begin(),input.begin()+1,input.end());
    }
}

int main()
{
    string input;
    cin>>input;
    printPermutations(input);
}