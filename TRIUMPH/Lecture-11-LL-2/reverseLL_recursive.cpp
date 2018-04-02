#include <bits/stdc++.h>
using namespace std;

template<typename T>
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

void print(Node<int> *root)
{
    Node<int> *temp = root;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node<int> *reverseLL(Node<int> *head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node<int> *smallAns = reverseLL(head->next);
    Node<int> *temp = smallAns;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head;
    head->next = NULL;

    return smallAns;
}

Node<int> *reverseLLOptim(Node<int> *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node<int> *smallOutput = reverseLLOptim(head->next);
    Node<int> *tail = head->next;
    tail->next = head;
    head->next = NULL;

    return smallOutput;
}

int main()
{
    Node<int> *root = NULL;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if(root == NULL)
        {
            root = new Node<int>(num);
        }
        else
        {
            Node<int> *node = new Node<int>(num);
            node->next = root;
            root = node;
        }
    }

    print(root);
    root = reverseLLOptim(root);
    cout << endl;
    print(root);
    return 0;
}