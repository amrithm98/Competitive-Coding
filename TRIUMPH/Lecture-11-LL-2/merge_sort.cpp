#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* merge(node *head1, node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  	node *temp1 = head1;
  	node *temp2 = head2;
  	
  	node *temp3 = NULL;
  
  	if(temp1->data <= temp2->data)
    {
      	temp3 = temp1;
      	temp1 = temp1->next;
    }
  	else
    {
      	temp3 = temp2;
      	temp2 = temp2->next;
    }
  	
  	node *newHead = temp3;
  	
  	while(temp1 && temp2)
    {
      	if(temp1->data <= temp2->data)
        {
          	temp3->next = temp1;
          	temp1 = temp1->next;
        }
      	else
        {
          	temp3->next = temp2;
          	temp2 = temp2->next;
        }
      	temp3 = temp3->next;
    }
  
  	while(temp1)
    {
      	temp3->next = temp1;
      	temp1 = temp1->next;
      	temp3 = temp3->next;
    }
  
  	while(temp2)
    {
      	temp3->next = temp2;
      	temp2 = temp2->next;
      	temp3 = temp3->next;
    }
  
  	return newHead;
}

node* findMid(node *head)
{
  node *slow = head;
  node *fast = head->next;
  
  while(slow && fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  node *temp = slow->next;
  slow->next = NULL;

  return temp;
}

node* mergeSort(node *head) {
    //write your code here
  
  	if(head == NULL || head->next == NULL)
    {
      return head;
    }
  
  	node *mid = findMid(head);
  	node *h1 = mergeSort(head);
  	node *h2 = mergeSort(mid);
  	head = merge(h1,h2);
  	return head;
}

void print(node *root)
{
    cout << endl;
    node *temp = root;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *root = NULL;
    int num;
    cin >> num;

    while(num != -1)
    {
        if(root == NULL)
            root = new node(num);
        else
        {
            node *nextNode = new node(num);
            nextNode->next = root;
            root = nextNode;
        }
        cin >>  num;
    }

    print(root);
    mergeSort(root);
    print(root);
    return 0;
}