/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  	Node *temp1 = head1;
  	Node *temp2 = head2;
  	
  	Node *temp3 = NULL;
  
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
  	
  	Node *newHead = temp3;
  	
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