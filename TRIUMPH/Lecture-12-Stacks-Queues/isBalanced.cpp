#include <bits/stdc++.h>

char match(char c)
{
  	if(c == ')')
      	return '(';
  	else if(c == '}')
      	return '{';
  	else if(c == ']')
      	return '[';
}

bool checkBalanced(char *exp) {
	// Write your code here
	stack<char> st;
  	for(int i = 0; exp[i] != '\0'; i++)
    {
      	char curr = exp[i];
      	if(curr == '(' || curr == '[' || curr == '{')
          st.push(curr);

      	else if(curr == ')' || curr == ']' || curr == '}')
        {
          	if(!st.empty())
            {
                char top = st.top();
                if(top == match(curr))
                    st.pop();
                else
                    return false;
            }
          	else
              	return false;
        }
          	
    }
  	return st.empty();
}