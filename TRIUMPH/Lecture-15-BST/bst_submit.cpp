#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
    BinaryTreeNode<int> *root;
    
    private:

    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *node,int data)
    {
        if(node == NULL)
        {
            node = new BinaryTreeNode<int>(data);
            return node;
        }
        if(node->data < data)
        {
            node->right = insert(node->right,data);
        }
        else if(node->data > data)
        {
            node->left = insert(node->left,data);
        }
        return node;
    }

    BinaryTreeNode<int> *deleteData(BinaryTreeNode<int> *node,int data)
    {
        if(node == NULL)
        {
            return NULL;
        }
        if(node->data == data)
        {
            if(node->left == NULL && node->right == NULL)
            {
                free(node);
                return NULL;
            }

            else if(node->left == NULL && node->right != NULL)
            {
                BinaryTreeNode<int> *nextNode = node->right;
                free(node);
                return nextNode;
            }

            else if(node->left != NULL && node->right == NULL)
            {
                BinaryTreeNode<int> *nextNode = node->left;
                free(node);
                return nextNode;
            }

            else if(node->left != NULL && node->right != NULL)
            {
                BinaryTreeNode<int> * inOrdSuc = node->right;

                while(inOrdSuc->left != NULL)
                    inOrdSuc = inOrdSuc->left;

                node->data = inOrdSuc->data;
                node->right = deleteData(node->right,inOrdSuc->data);
                
                return node;
            }
        }

        if(node->data < data)
            node->right = deleteData(node->right,data);

        else if(node->data > data)
            node->left = deleteData(node->left,data);

        return node;
        
    }

    bool hasData(int data,BinaryTreeNode<int> *root)
    {
        if(root == NULL)
            return false;

        if(root->data == data)
            return true;

        if(root->data < data)
        {
            return hasData(data,root->right);
        }
        else if(root->data > data)
        {
            return hasData(data,root->left);
        }
    }

    void printTree(BinaryTreeNode<int> *node)
    {
        if(node == NULL)
            return;

        cout << node->data << ":";

        if(node->left != NULL)
            cout << "L:" << node->left->data << ",";

        if(node->right != NULL)
            cout << "R:" << node->right->data;
        cout << endl;

        printTree(node->left);
        printTree(node->right);
    }

    public:

    BST()
    {
        root = NULL;
    }

    void insert(int data)
    {
        root = insert(root,data);
    }

    void deleteData(int data)
    {
        root = deleteData(root,data);
    }

    bool hasData(int data)
    {
        return hasData(data,root);
    }

    void printTree()
    {
        printTree(root);
    }
    
};

int main()
{
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                break;
        }
    }
    return 0;

}