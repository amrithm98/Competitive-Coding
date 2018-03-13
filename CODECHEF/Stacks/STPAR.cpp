#include <bits/stdc++.h>
using namespace std;

bool isPossible(queue<int> arr, int n)
{
    stack<int> st;
    int order = 1;

    bool flag = true;

    while(!(arr.empty() && st.empty()))
    {
        if(!arr.empty() && arr.front() == order)
        {
            order++;
            arr.pop();
        }
        else
        {
            bool fromStack = false;
            if(!st.empty())
            {
                if(st.top() == order)
                {
                    fromStack = true;
                    st.pop();
                    order++;
                }
                else if(arr.empty())
                {
                    flag = false;
                    break;
                }
            }
            if(!arr.empty() && !fromStack)
            {
                st.push(arr.front());
                arr.pop();
            }
        }
    }

    return flag;
}

int main()
{
    int n;
    cin >> n;

    do
    {
        queue<int> arr;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr.push(a);
        }
        
        cout << ((isPossible(arr,n) == 1)?"yes":"no") << endl;

        cin >> n;
    }while(n != 0);
    return 0;
}