#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

bool isOperator(char c)
{
    if(c == '+'  || c == '*' || c == '/' || c == '-' || c == '^')
        return true;
    else
        return false;
}
void evaluatePostfix(char exp[]) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the required output.
     * Taking input is handled automatically.
     */
  	stack<char> st;
  	string postfix = "";
    string postEval = "";

  	for(int i = 0; exp[i] != '\0'; i++)
    {
      	char curr = exp[i];

      	if(curr == '(')
            st.push(curr);

        else if(curr == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                postEval += st.top();
                st.pop();
            }

            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
                return;
                
        }
        else if(isalnum(curr))
        {
            postfix += curr;
            postEval += curr;
        }
        else
        {
            if(exp[i-1] != ')')
                postEval += ' ';    //Handling multiple digits
            while(!st.empty() && prec(curr) <= prec(st.top()))
            {
                postfix += st.top();
                postEval += st.top();
                st.pop();
            } 
            st.push(curr);
        }
    }
    while(!st.empty())
    {
        postfix += st.top();
        postEval += st.top();
        st.pop();
    }
    cout << postfix << endl;
    stack<int> eval;

    for(int i = 0; i < postEval.size();)
    {
        char curr = postEval[i];
        if(isOperator(curr))
        {
            int op2 = eval.top();
            eval.pop();
            int op1 = eval.top();
            eval.pop();

            if(curr == '+')
                eval.push(op1+op2);
            else if(curr == '-')
                eval.push(op1-op2);
            else if(curr == '*')
                eval.push(op2*op1);
            else if(curr == '/')
                eval.push(op1/op2);
            i++;
        }
        else
        {
            int num = 0;
            while(postEval[i] != ' ' && i < postEval.size() && !isOperator(postEval[i]))
            {
                num = num*10 + (postEval[i]-'0');
                i++;
            }
            if(postEval[i] == ' ')
                i++;
            eval.push(num);
        }
    }

    cout << eval.top() << endl;

}

int main()
{
    char expr[100];
    cin >> expr;
    evaluatePostfix(expr);
    return 0;
}
