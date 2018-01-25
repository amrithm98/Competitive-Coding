#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int val)
{
    Node *n = new Node;
    n->data = val;
    n->next = NULL;
    return n;
}

void insert(Node *head,int val)
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode(val);
}

int findLoop(Node *head)
{
    Node *slow = head,*fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            cout << slow->data << endl;
            return 1;
        }

    }
    return 0;
}

int main()
{
    Node *head = NULL;
    head = newNode(5);
    head->next = newNode(6);
    head->next->next = newNode(7);
    // head->next->next->next = NULL;
    head->next->next->next = head->next;
    cout << findLoop(head);
    return 0;
}