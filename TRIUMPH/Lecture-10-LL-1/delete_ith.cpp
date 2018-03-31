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

Node* deleteNode(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  	Node *temp = head;
  	int cnt = 0;
  
  	if(i == 0)
    {
      	head = head->next;
      	free(temp);
      	return head;
    }
  	else
    {
      	while(temp != NULL)
        {
          	cnt++;
          	if(cnt == i && temp->next != NULL)
            {
              	Node *del = temp->next;
              	temp->next = del->next;
              	free(del);
              	break;
            }
          	temp = temp->next;
        }
      
      	return head;
    }
  	
    
}
