#include <bits/stdc++.h>
using namespace std;

//HEAD is not a dummy here

struct node 
{
    int data;
    node *next;
};

node *newNode(int value)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = value;
    n->next = NULL;
    return n;
}

void insert(node *head,int value)
{
    node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode(value);
}

void printList(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *reverse_ll(node *head)
{
    node *curr,*next,*prev;
    curr = head;
    prev = NULL;
    next = NULL;

    while(curr != NULL)
    {

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    node *head = NULL;
    int n;
    cin >> n;
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

    printList(head);
    head = reverse_ll(head);
    printList(head);

    return 0;
}