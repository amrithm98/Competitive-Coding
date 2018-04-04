#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};


template <typename T>
class Stack
{   
    Node<T> *head;
    int size;

    public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    void push(T data)
    {
        if(head == NULL)
            head = new Node<T>(data);
        else
        {
            Node<T> *node = new Node<T>(data);
            node->next = head;
            head = node;
        }
        size++;
    }

    void pop()
    {
        if(head)
        {
            Node<T> *temp = head;
            head = head->next;
            free(temp);
            size--;
        }
        else
            cout << "\nStack UnderFlow\n";
    }

    T top()
    {
        if(head != NULL)
            return head->data;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Stack<int> st;
    st.push(10);
    cout << st.top() << endl;
    st.push(20);
    cout << st.top() << endl;
    st.push(30);
    cout << st.top() << endl;
    cout << "\nSize: " << st.getSize() << endl;
    st.pop();
    st.pop();
    cout << "\nSize: " << st.getSize() << endl;
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();

    return 0;
}