#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    node *left,*right;
};

node* newNode(int data)
{
    node *root = (node *)malloc(sizeof(node));
    root->data = data;
    root->left = root->right = NULL;
}

void inOrder_get(node *root,vector<int> &elems)
{
    if(root != NULL)
    {
        inOrder_get(root->left,elems);
        elems.push_back(root->data);
        inOrder_get(root->right,elems);
    }
}

void inOrder_put(node *root,vector<int> &elems,int *index)
{
    if(root != NULL)
    {
        inOrder_put(root->left,elems,index);
        root->data = elems[*index];
        *index = *index + 1;
        inOrder_put(root->right,elems,index);
    }
}

void inOrder_print(node *root)
{
    if(root != NULL)
    {
        inOrder_print(root->left);
        cout<<root->data<<" ";
        inOrder_print(root->right);
    }
}

node* convertToBST(node *root,vector<int> &elems)
{
    inOrder_get(root,elems);
    sort(elems.begin(),elems.end());
    // for(int i = 0; i < elems.size(); i++)
    //     cout<<elems[i]<<" ";
    int index = 0;
    inOrder_put(root,elems,&index);
    return root;
}

int main()
{
    node *root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    vector<int> elems;

    node *bst = convertToBST(root,elems);
    cout<<"\nINORDER BST : \n";
    inOrder_print(root);
    return 0;
}