// Following is the Binary Tree node structure
/**************
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

void printLevelWise(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
	queue<BinaryTreeNode<int>*> q;
  	q.push(root);
  	while(!q.empty())
    {
      	BinaryTreeNode<int> *n = q.front();
      	q.pop();
      	cout << n->data << ":L:" << (n->left == NULL ? -1 : n->left->data) << ",R:";
        cout << (n->right == NULL ? -1 : n->right->data) << endl;
      	if(n->left)
          	q.push(n->left);
      	if(n->right)
          	q.push(n->right);
    }
}
