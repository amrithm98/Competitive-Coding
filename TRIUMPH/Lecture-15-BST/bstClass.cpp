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

template<typename T>
class BST
{
    BinaryTreeNode<T> *root;
    
    private:

    BinaryTreeNode<T> *insert(BinaryTreeNode<T> *node,T data)
    {
        if(node == NULL)
        {
            node = new BinaryTreeNode<T>(data);
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

    BinaryTreeNode<T> *deleteData(BinaryTreeNode<T> *node,T data)
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
                BinaryTreeNode<T> *nextNode = node->right;
                free(node);
                return nextNode;
            }

            else if(node->left != NULL && node->right == NULL)
            {
                BinaryTreeNode<T> *nextNode = node->left;
                free(node);
                return nextNode;
            }

            else if(node->left != NULL && node->right != NULL)
            {
                BinaryTreeNode<T> * inOrdSuc = node->right;

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

    bool hasData(T data,BinaryTreeNode<T> *root)
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

    public:

    BST()
    {
        root = NULL;
    }

    void insert(T data)
    {
        root = insert(root,data);
    }

    void deleteData(T data)
    {
        root = deleteData(root,data);
    }

    bool hasData(T data)
    {
        return hasData(data,root);
    }

    void printTree()
    {
        if(root == NULL)
            return;
        queue<BinaryTreeNode<T>*> q;
        q.push(root);
        while(!q.empty())
        {
            BinaryTreeNode<T> *n = q.front();

            q.pop();

            cout << n->data << ":L:" << (n->left == NULL ? -1 : n->left->data) << ",R:";

            cout << (n->right == NULL ? -1 : n->right->data) << endl;

            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
    }
    
};

int main()
{
    BST<int> *tree = new BST<int>();
    int choice, input;

    while(true)
    {
        cin>>choice;
        switch(choice)
        {
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
            case 4:
                tree->printTree();
                break;
        }
    }

    return 0;
}