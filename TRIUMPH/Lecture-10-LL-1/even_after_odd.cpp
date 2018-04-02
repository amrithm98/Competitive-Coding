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

//Handle only odd and even cases. Maintain 4 pointers and do the job

node* arrange_LinkedList(node* head)
{
    //write your code here
  	node *oddHead = NULL;
    node *oddTail = NULL;
   	node *evenHead = NULL;
  	node *evenTail = NULL;
  
  	node *temp = head;
  
  	while(temp != NULL)
    {
      	if(temp->data % 2 == 1)
        {
          	if(oddHead != NULL)
            {
              	oddTail->next = temp;
              	oddTail = temp;
            }
          	else
            {
              	oddHead = temp;
              	oddTail = temp;
            }
        }
      	else
        {
          	if(evenHead != NULL)
            {
              	evenTail->next = temp;
              	evenTail = temp;
            }
          	else
            {
              	evenHead = temp;
              	evenTail = temp;
            }
        }
      
      	temp = temp->next;
    }
  
  	if(oddHead == NULL)
      	return evenHead;
   
  	oddTail->next = evenHead;
  
  	if(evenHead != NULL)
  		evenTail->next = NULL;
  
  	return oddHead;
}
