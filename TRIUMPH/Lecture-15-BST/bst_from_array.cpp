// Following is the Binary Tree node structure
#include<bits/stdc++.h>
using namespace std;

template <typename T>
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


BinaryTreeNode<int>* completeTree(BinaryTreeNode<int>* root,int *input, int si,int ei)
{
  	if(si > ei)
    	return NULL;
  
    int mid = (si+ei)/2;
  
    root = new BinaryTreeNode<int>(input[mid]);
    root->left = completeTree(root->left,input,si,mid-1);
    root->right = completeTree(root->right,input,mid+1,ei);
  
  	return root;
}



BinaryTreeNode<int>* constructTree(int *input, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */	
  	BinaryTreeNode<int>* root = NULL;
  
    root = completeTree(root,input,0,n-1);
  
  	return root;
}
