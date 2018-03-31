//head is the head of you linked list
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

node *midList(node *head)
{
  	node *slow = head;
  	node *fast = head->next;
  
  	while(slow && fast && fast->next)
    {
      	slow = slow->next;
      	fast = fast->next->next;
    }
  	return slow;
}

node *reverseLL(node *head)
{
  	node *prev = NULL, *curr = NULL, *next = NULL;
  	curr = head;
  
  	while(curr)
    {
      	next = curr->next;
      	curr->next = prev;
      	prev = curr;
      	curr = next;
    }
  
  	return prev;
}

bool check_palindrome(node* head)
{
    //write your code here
  	node *mid = midList(head);
  	node *rev = reverseLL(mid->next);
  	node *temp = head;
  	/*cout << mid->data << endl;
  	while(temp != NULL)
    {
      	cout << temp->data << " ";
      	temp = temp->next;
    }*/
  
  	while(temp && rev)
    {
      	if(temp->data != rev->data)
        {
          	return false;
        }
      	temp = temp->next;
      	rev = rev->next;
    }
  	return true;
}