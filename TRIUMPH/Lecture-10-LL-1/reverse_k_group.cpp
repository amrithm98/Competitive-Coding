//head is the head of the linked list, n is number of elements to be reversed
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/

node* kReverse(node*head,int n)
{
   if(head == NULL)
   {
     	return head;
   }
  
  	node *curr = head;
  	node *prev = NULL;
  	node *next;
  
  	int k = n;
  
  	while(curr != NULL && k != 0)
    {
      	next = curr->next;
      	curr->next = prev;
      	prev = curr;
      	curr = next;
      	k--;
    }
  
  	head->next = kReverse(next,n);
  	return prev;
}
