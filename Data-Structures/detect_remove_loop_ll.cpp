#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}

struct Node *newNode(int data)
{
    struct Node *node=(struct Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

void remove_loop(struct Node *loop,struct Node *head)
{
    struct Node *ptr1,*ptr2;
    ptr1=head;
    ptr2=loop;

    int loopCount=1;
    while(ptr2->next!=loop)
    {
        ptr2=ptr2->next;
        loopCount++;
    }

    ptr1=head;
    ptr2=head;

    for(int i=0;i<loopCount;i++)
        ptr2=ptr2->next;
    
    while(ptr1!=ptr2)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    ptr2=ptr2->next;
    while(ptr2->next!=ptr1)
    {
        ptr2=ptr2->next;
    }
    ptr2->next=NULL;
    printList(head);
}

void detect_loop(struct Node *head)
{
    struct Node *slow=head,*fast=head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            remove_loop(slow,head);
            break;
        }
    }
}

int main()
{
    struct Node* head=NULL;
    head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);
    head->next->next->next->next=newNode(5);
    head->next->next->next->next->next=head->next->next->next;
    detect_loop(head);
}