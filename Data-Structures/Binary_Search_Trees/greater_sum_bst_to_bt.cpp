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

void buildGreaterTree(node *root,int *sum)
{
    if(root == NULL)
    {
        return;
    }
    buildGreaterTree(root->right,sum);
    *sum = *sum + root->data;
    root->data = *sum;
    buildGreaterTree(root->left,sum);
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

    cout<<"\nGreater Sum Tree: ";

    int sum = 0;
    buildGreaterTree(root,&sum);

    inOrder(root);

    return 0;
}