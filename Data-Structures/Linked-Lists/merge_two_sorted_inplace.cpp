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

node *mergeSorted(node *head1,node *head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;

    if(head1->data < head2->data)
    {
        head1->next = mergeSorted(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next = mergeSorted(head1,head2->next);
        return head2;
    }
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

    merge = mergeSorted(head1,head2);
    printList(merge->next);

    return 0;
} 