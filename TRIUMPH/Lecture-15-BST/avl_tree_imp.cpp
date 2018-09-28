#include <bits/stdc++.h>
using namespace std;

class TreeNode
{

    public:
        int data;
        int height;
        TreeNode *left, *right;

        TreeNode(int d)
        {
            data = d;
            left = right = NULL;
            height = 1;
        }
};

int getHeight(TreeNode *node)
{
    return (node == NULL)? 0 : node->height; 
}

int balanceFactorr(TreeNode *node)
{
    return getHeight(node->left) - getHeight(node->right);
}

void fixHeight(TreeNode *node)
{
    int hl = getHeight(node->left);
    int hr = getHeight(node->right);
    node->height = 1 + (max(hl,hr));
}

TreeNode *leftRotate(TreeNode *root)
{
    TreeNode *q = root->right;
    root->right = q->left;
    q->left = root;
    fixHeight(root);
    fixHeight(q);
    
    return q;
}

TreeNode *rightRotate(TreeNode *root)
{
    TreeNode *q = root->left;
    root->left = q->right;
    q->right = root;
    fixHeight(root);
    fixHeight(q);

    return q;
}

TreeNode *balanceNode(TreeNode *root)
{
    fixHeight(root);

    if(balanceFactorr(root) == 2)
    {
        if()
    }

    if(balanceFactorr(root) == -2)
    {

    }

    return root;
}

int main()
{

    return 0;
}