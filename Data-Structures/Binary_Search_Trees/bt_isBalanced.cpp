#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

node* insert(node *root,int value)
{
    if(root == NULL)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if(value < root->data)
    {
        root->left = insert(root->left,value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right,value);
    }

    return root;
}

void inOrder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

bool isBalanced(node *root,int *height)
{

    int lh = 0,rh = 0,l = 0,r = 0;
    if(root == NULL)
    {
        *height = 0;
        return 1;
    }
    l = isBalanced(root->left,&lh);
    r = isBalanced(roo->tright,&rh);

    *height = max(lh,rh) + 1;

    if(abs(lh-rh) >= 2)
    {
        return 0;
    }
    else
    {
        return l && r;
    }

}

int main()
{
    int n;
    cin >> n;
    node *root = NULL;
    cout<<"Enter n elements: ";
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insert(root,val);
    }   

    cout<<"\nOriginal Tree: ";
    inOrder(root);

    int height = 0;
    bool bal = isBalanced(root,&height);

    cout<<"\nBalanced: "<<bal;

    return 0;

}