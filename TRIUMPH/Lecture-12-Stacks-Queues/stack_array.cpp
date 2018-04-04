#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
    private:
        T *arr;
        int capacity;
        int topIndex;
    public:
        Stack()
        {
            this->capacity = 4;
            arr = new T[capacity];
            topIndex = 0;
        }
        void push(T num)
        {
            if(topIndex == capacity)
            {
                T *newData = new T[2*capacity];
                for(int i = 0; i < capacity; i++)
                    newData[i] = arr[i];
                delete [] arr;
                arr = newData;
                capacity = 2*capacity;
            }
            arr[topIndex++] = num;
        }
        void pop()
        {
            if(topIndex == 0)
            {
                cout << "STACK UNDERFLOW !!!";
                return;
            }
            topIndex--; 
        }
        T top()
        {
            if(topIndex != 0)
                return arr[topIndex-1];
        }

        bool isEmpty()
        {
            if(topIndex == 0)
                return true;
            else    
                return false;
        }

        int size()
        {
            return topIndex;
        }

};

int main()
{
    Stack<int> st;

    st.push(10);
    st.push(20);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.push(100);
    cout << st.top() << endl;
    st.push(200);
    st.push(300);
    cout << st.size() << endl;
    st.push(400);

    cout << st.isEmpty() << endl;
    return 0;
}