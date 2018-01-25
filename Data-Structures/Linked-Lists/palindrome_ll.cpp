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

Node *getMiddle(Node *head)
{
    Node *slow = head,*fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverse_ll(Node *head)
{
    Node *curr,*prev,*next;
    prev = next = NULL;
    curr = head;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void checkPalin(Node *head)
{
    Node *mid = getMiddle(head);
    cout << mid->data << endl;
    Node *tail = reverse_ll(mid);
    Node *temp = head;
    mid = tail;

    while(mid->next != NULL)
        mid = mid->next;

    while(temp != mid)
    {
        if(temp->data == tail->data)
        {
            temp = temp->next;
            tail = tail->next;
        }
        else
        {
            break;
        }
    }
    if(temp == mid)
    {
        cout << "\nPalindrome";
    }
    else
    {
        cout << "\nNot Palindrome";
    }
}

int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if(head == NULL)
        {
            head = newNode(val);
        }
        else
        {
            insert(head,val);
        }
    }
    checkPalin(head);
}