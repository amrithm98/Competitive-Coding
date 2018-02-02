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

Node *lca(Node *root,int a,int b)
{
    if(root == NULL)
        return NULL;

    if((root->data == a || root->data == b))
        return root;

    Node *lca_left = lca(root->left,a,b);
    Node *lca_right = lca(root->right,a,b);

    if(lca_left != NULL && lca_right != NULL)
        return root;
    
    if(lca_left != NULL)
        return lca_left;
    else if(lca_right != NULL)
        return lca_right;
}

int main()
{
    Node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->right = newNode(6);
    root->right->left = newNode(7);
    root->right->right = newNode(8);

    inOrder(root);
    cout << endl;

    int a,b;
    cin >> a >> b;
    cout << "\nLCA: " << lca(root,a,b)->data << endl;

    return 0;
}