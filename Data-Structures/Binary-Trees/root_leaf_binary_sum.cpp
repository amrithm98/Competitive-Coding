#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};

Node *newNode(int val)
{
    Node *n = new Node;
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void inOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int rootToLeafPathSum(Node *root,int sum)
{
    if(root == NULL)
    {
        //This is done so as not to recompute the path sum if a node has a left but not a right child
        return 0;
    }

    sum = sum*2 + root->data;

    if(root->left == NULL && root->right == NULL)
    {
        return sum;
    }

    return rootToLeafPathSum(root->left,sum) + rootToLeafPathSum(root->right,sum);
}

int main()
{
    //Binary Numbers in a tree. COmputer sum of all root->leaf path binary noes 
    //We don't compute overlapping path sum twice
    
    Node *root = newNode(1);
    root->left = newNode(0);
    root->right = newNode(1);
    root->left->right = newNode(0);
    root->right->left = newNode(1);
    root->right->right = newNode(1);

    inOrder(root);
    cout << endl;

    cout << rootToLeafPathSum(root,0) << endl;
    return 0;
}