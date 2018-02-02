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

bool checkSymmetry(Node *subtree1,Node *subtree2)
{
    if(subtree1 == NULL && subtree2 == NULL)
    {
        return true;
    }

    if(subtree1 != NULL && subtree2 != NULL)
    {
        bool flag = (subtree1->data == subtree2->data); 
        return (flag && checkSymmetry(subtree1->left,subtree2->right) && checkSymmetry(subtree2->left,subtree1->right));
    }
    else
        return false;


}

int main()
{

    Node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->right = newNode(6);
    root->right->left = newNode(7);
    // root->right->right = newNode(8);

    Node *root1 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(3);
    root1->left->right = newNode(8);
    root1->left->right->right = newNode(9);
    root1->right->left = newNode(8);
    root1->right->left->left = newNode(9);
    // root->right->right = newNode(8);

    inOrder(root);
    cout << endl;
    inOrder(root1);
    cout << endl;

    //Another Method. Check if InOrder is PALINDROME !!!!

    cout << "\nCheck Symmetry 0 : " << checkSymmetry(root->left,root->right) << endl;
    cout << "\nCheck Symmetry 1 : " << checkSymmetry(root1->left,root1->right) << endl;

    return 0;
}