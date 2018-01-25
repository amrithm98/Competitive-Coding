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

void printNthFromLast(Node *head,int n)
{
    Node *slow = head,*ref = head;
    int i = 1;
    while(i <= n)
    {
        ref = ref->next;
        i++;
    }
    while(ref != NULL)
    {
        ref = ref->next;
        slow = slow->next;
    }
    cout << "\nNth Node from Last : " << slow->data <<endl;
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
    cin >> n;

    printNthFromLast(head,n);
    
    return 0;
}