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

Node* deleteNodeRec(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  	if(head == NULL)
    {
      	return head;
    }
  	if(i == 0)
    {
      	Node *temp = head;
      	head = head->next;
      	free(temp);
      	return head;
    }
  	head->next = deleteNodeRec(head->next,i-1);
    return head;
}