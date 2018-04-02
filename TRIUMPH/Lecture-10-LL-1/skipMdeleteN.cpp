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

node* skipMdeleteN(node  *head, int M, int N) {
    // Write your code here
	node *temp = head;
  
  	while(temp)
    {
      	int k = 0;
      	while(temp && k < M-1)
        {
          	temp = temp->next;
          	k++;
        }
      	node *tail = temp;
      	
      	if(temp != NULL)
      		temp = temp->next;
      
      	while(temp && k < M + N -1)
        {
          	node *next = temp;
          	temp = temp->next;
          	free(next);
          	k++;
        }
      	if(tail != NULL)
      		tail->next = temp;
    }
  
  	return head;
      
}
