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

void preOrder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
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

node* search(node *root,int value)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(value == root->data)
    {
        return root;
    }
    if(value < root->data)
    {
        return search(root->left,value);
    }
    else if(value > root->data)
    {
        return search(root->right,value);
    }
}

node* inOrderSuccessor(node *root)
{
    node *temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node* deleteNode(node *root,int value)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(value < root->data)
    {
        root->left = deleteNode(root->left,value);
    }
    else if(value > root->data)
    {
        root->right = deleteNode(root->right,value);
    }
    else
    {
        if(root->left == NULL)
        {
            node *temp = (node*)malloc(sizeof(node));
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            node *temp = (node*)malloc(sizeof(node));
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node* successor = inOrderSuccessor(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right,successor->data);
        }
    }
    return root;
} 

int height(node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = 1 + height(root->left);
        int right_height = 1 + height(root->right);
        return max(left_height,right_height);
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
    while(1)
    {
            cout<<"\nOPERATIONS IMPLEMENTED\n=========================";
            cout<<"\n1. InOrder Traversal";
            cout<<"\n2. PreOrder Traversal";
            cout<<"\n3. PostOrder Traversal";
            cout<<"\n4. Search Element";
            cout<<"\n5. Delete Element";
            cout<<"\n6. Height of BST";
            cout<<"\nEnter Your Choice: ";
            int ch;
            cin >> ch;
            node *ans,*temp;
            switch(ch)
            {
                case 1:
                    cout<<"\nInOrder : ";
                    inOrder(root);
                    break;
                case 2:
                    cout<<"\nPreOrder : ";
                    preOrder(root);
                    break;
                case 3:
                    cout<<"\nPostOrder : ";
                    postOrder(root);
                    break;
                case 4:
                    cout<<"\nEnter Search Element: ";
                    int src;
                    cin >> src;
                    ans = search(root,src);
                    if(ans != NULL)
                    {
                        cout<<"\nFOUND "<<ans->data;
                    }
                    else
                    {
                        cout<<"\nNOT FOUND";
                    }
                    break;
                case 5:
                    cout<<"\nEnter Element To Delete: ";
                    int elm;
                    cin >> elm;
                    root = deleteNode(root,elm);
                    break;
                case 6:
                    cout<<height(root)<<endl;
                    break;
            }
    }

}