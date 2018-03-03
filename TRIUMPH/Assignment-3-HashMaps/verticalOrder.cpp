#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode 
{
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

void goVertical(BinaryTreeNode<int>* root ,map<int,vector<int>> &verticalOrder, int dist)
{
  	if(root == NULL)
    {
      return;
    }
    verticalOrder[dist].push_back(root->data);
  	goVertical(root->left,verticalOrder,dist-1);
  	goVertical(root->right,verticalOrder,dist+1);
}

void printBinaryTreeVerticalOrder(BinaryTreeNode<int>* root) 
{	 
  	map<int,vector<int>> verticalOrder;
  	goVertical(root,verticalOrder,0);
    for(auto it : verticalOrder)
    {
        for(auto abc : it.second)
        {
            cout << abc << " ";
        }
        cout << endl;
    }
}

int main()
{
    BinaryTreeNode<int> *root;
    root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    (root->left)->left = new BinaryTreeNode<int>(4);
    (root->left)->right = new BinaryTreeNode<int>(5);
    (root->right)->left = new BinaryTreeNode<int>(6);
    (root->right)->right = new BinaryTreeNode<int>(7);

    printBinaryTreeVerticalOrder(root);

    return 0;
}

