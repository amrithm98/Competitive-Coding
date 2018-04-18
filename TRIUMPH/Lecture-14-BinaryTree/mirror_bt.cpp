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

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
	if(root == NULL)
    {
      	return;
    }
  	mirrorBinaryTree(root->left);
  	mirrorBinaryTree(root->right);
  	BinaryTreeNode<int>* temp = root->left;
  	root->left = root->right;
  	root->right = temp;
}
