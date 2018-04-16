// Following is the Binary Tree node structure
/**************
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
 
 class BinaryTreeNode {
 public :
 T data;
 BinaryTreeNode<T> *left;
 BinaryTreeNode<T> *right;
 
 BinaryTreeNode(T data) {
 this -> data = data;
 left = NULL;
 right = NULL;
 }
 };
 ***************/
#include <bits/stdc++.h>
using namespace std;

void inOrderTraversal(BinaryTreeNode<int>* root, Node<int> * &head, Node<int> * &tail)
{
  	if(root == NULL)
    {
      	return;
    }
  	
  	inOrderTraversal(root->left,head,tail);
  
  	if(head == NULL)
    {
      	(head) = new Node<int>(root->data);
      	(tail) = (head);
    }
  	else
    {
      	(tail)->next = new Node<int>(root->data);
      	(tail) = (tail)->next;
    }
  
  	inOrderTraversal(root->right,head,tail);
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  	Node<int>* head = NULL ,*tail = NULL;
  
  	inOrderTraversal(root,head,tail);
  	tail->next = NULL;
  
  	return head;
    
}