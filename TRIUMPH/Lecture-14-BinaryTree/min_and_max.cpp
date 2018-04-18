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
 
 // PairAns class -
 class PairAns {
    public :
        int min;
        int max;
 };
 
***************/
#include <bits/stdc++.h>
using namespace std;

PairAns minMax(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  	if(root == NULL)
    {
      	PairAns p;
      	p.min = INT_MAX;
      	p.max = INT_MIN;
      	return p;
    }
  
  	PairAns p = minMax(root->left);
  	p.min = min(p.min,root->data);
  	p.max = max(p.max,root->data);
  
  	PairAns q = minMax(root->right);
  	q.min = min(q.min,root->data);
  	q.max = max(q.max,root->data);
  
  	PairAns a;
  	a.min = min(p.min,q.min);
  	a.max = max(p.max,q.max);
  
  	return a;

}
