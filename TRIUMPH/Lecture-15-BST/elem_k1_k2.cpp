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

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
  	if(root == NULL)
    {
      	return ;
    }
  
  	if(root->data < k1)
        return elementsInRangeK1K2(root->right,k1,k2);
  
  	if(root->data > k2)
      	return elementsInRangeK1K2(root->left,k1,k2);
  
    elementsInRangeK1K2(root->left,k1,k2);
   	cout << root->data << " ";
  	elementsInRangeK1K2(root->right,k1,k2);

}
