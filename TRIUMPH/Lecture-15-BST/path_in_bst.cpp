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

vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  	if(root == NULL)
      	return NULL;
  
  	if(root->data == data)
    {
      	vector<int> *op = new vector<int>();
      	op->push_back(data);
      	return op;
    }
  
  	vector<int> *leftOp = findPath(root->left,data);
  	if(leftOp != NULL)
    {
      	leftOp->push_back(root->data);
      	return leftOp;
    }
  	
  	vector<int> *rightOp = findPath(root->right,data);
  	if(rightOp != NULL)
    {
      	rightOp->push_back(root->data);
      	return rightOp;
    }
  	else
      	return NULL;

}
