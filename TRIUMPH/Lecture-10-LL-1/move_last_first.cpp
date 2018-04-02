#include <bits/stdc++.h>
using namespace std;
/*************
 Following is the Node structure already written.

 template <typename T>
 class Node {
	public:
	T data;
	Node* next;
 
	Node(T data) {
 next = NULL;
 this->data = data;
	}
 
	~Node() {
 if (next != NULL) {
 delete next;
 }
	}
 };
 
*************/

//1 2 3 4 5 6 -1
//6 1 2 3 4 5 -1

Node<int>* moveToFront(Node<int> *head_ref) {
	// Write your code here
    Node<int> *temp = head_ref;
  	
  	while(temp->next != NULL && temp->next->next != NULL)
    {
      temp = temp->next;
    }
  
  	Node<int> *last = temp->next;
	temp->next = NULL;
  	last->next = head_ref;
  	head_ref = last;
  	return head_ref;
}
