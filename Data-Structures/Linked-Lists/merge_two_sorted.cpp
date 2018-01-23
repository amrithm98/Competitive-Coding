#include <bits/stdc++.h>
using namespace std;

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
    while(temp->next != NULL)
    {
        cout << temp->next->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void mergeSorted(node *head1,node *head2,node *head3)
{
    node *temp1 = head1;
    node *temp2 = head2;
    node *curr = head3;
    while(temp1->next != NULL && temp2->next != NULL)
    {
        if(temp1->next->data <= temp2->next->data)
        {
            curr->next = newNode(temp1->next->data);
            temp1 = temp1->next;
        }
        else
        {
            curr->next = newNode(temp2->next->data);
            temp2 = temp2->next;
        }
        curr = curr->next;
    }
    if(temp1->next != NULL)
        curr->next = temp1->next;
    else
        curr->next = temp2->next;
}

int main()
{
    node *head1 = (node *)malloc(sizeof(node));
    head1->next = NULL;
    node *head2 = (node *)malloc(sizeof(node));
    head2->next = NULL;
    node *merge = (node *)malloc(sizeof(node));
    merge->next = NULL;

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert(head1,val);
    }
    for(int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        insert(head2,val);
    }

    printList(head1);
    printList(head2);

    mergeSorted(head1,head2,merge);
    printList(merge);

    return 0;
}