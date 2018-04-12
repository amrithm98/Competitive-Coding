#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &s){
	// Write your code here
	stack<int> temp;

    while(!s.empty())
    {
        if(temp.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        else
        {   
            if(!s.empty() && !temp.empty() && temp.top() < s.top())
            {
                int push = s.top();
                s.pop();
            }
            
            while(!s.empty() && !temp.empty() && temp.top() < s.top())
            {
                int pop = temp.top();
                s.push(pop);
                temp.pop();
            }

            while(!s.empty() && !temp.empty() && s.top() < temp.top())
            {
                int pop = s.top();
                temp.push(pop);
                s.pop();
            }
        }
    }

    while(!temp.empty())
    {
        int top = temp.top();
        cout << top << " ";
        temp.pop();
    }
}


int main()
{
    stack<int> st;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        st.push(num);
    }
    sortStack(st);
    return 0;
}