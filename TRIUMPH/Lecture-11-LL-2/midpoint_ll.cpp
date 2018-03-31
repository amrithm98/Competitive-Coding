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

node* midpoint_linkedlist(node *head)
{
    // Write your code here
	node *slow = head;
  	node *fast = head->next;
  	while(slow && fast && fast->next)
    {
      	slow = slow->next;
      	fast = fast->next->next;
    }
  	return slow;
}
