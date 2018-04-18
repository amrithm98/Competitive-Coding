// Following is the Node and Binary Tree node structure

/**************
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
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


vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
	queue<BinaryTreeNode<int>*> q;
  	q.push(root);
  
  	vector<node<int>*> arr;
  	
  	int nodeCount = 0;
  
  	while(1)
    {
      	int nodeCount = q.size();
      	if(nodeCount == 0)
          break;
      	
        node<int> *h1 = NULL,*t1 = NULL;
      	while(nodeCount > 0)
        {
          	BinaryTreeNode<int> *nd = q.front();
            q.pop();
          	if(h1 == NULL)
            {
              	h1 = new node<int>(nd->data);
              	t1 = h1;
            }
          	else
            {
              	t1->next  = new node<int>(nd->data);
              	t1 = t1->next;
            }
          	
          	if(nd->left)
              	q.push(nd->left);
          	if(nd->right)
              	q.push(nd->right);
          
         	nodeCount--;
        }
      	t1->next = NULL;
      	arr.push_back(h1);
    }
  	return arr;
}