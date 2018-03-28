#include<bits/stdc++.h>
using namespace std;

class BTreeNode
{
    public:

    int t;
    bool leaf;
    vector<BTreeNode*> children;
    vector<int> keys;

    BTreeNode(int t,bool lf)
    {
        this->t = t;
        this->leaf = lf;
    }

    void traverse()
    {
        for(int i = 0; i < keys.size(); i++)
        {
            if(leaf == false)
                children[i]->traverse();
            
            cout << keys[i] << " ";

        }

        if(leaf == false)
            children[children.size()-1]->traverse();
    }

    BTreeNode *search(int key)
    {
        int i = 0;

        while(i < keys.size() && keys[i] < key)
            i++;

        if(keys[i] == key)
            return this;

        if(leaf == true)
            return NULL;
            
        return children[i]->search(key);
    }

    void insertNotFull(int k)
    {

    }

    void splitChild(int splitIndex,BTreeNode* y)
    {

    }

};

class BTree
{
    public:
    BTreeNode *root;
    int t;

    BTree(int t)
    {
        this->t = t;
        root = NULL;
    }

    void traverse()
    {
        if(root != NULL)
            root->traverse();
    }

    BTreeNode *search(int key)
    {
        if(root != NULL)
        {
            return root->search(key);
        }
        else    
            return NULL;
    }

    void insert(int key)
    {
        if(root == NULL)
        {
            root = new BTreeNode(t,true);
            root->keys.push_back(key);
        }
        else
        {
            if(root->keys.size() == 2*t-1)
            {
                BTreeNode *node = new BTreeNode(t,false);
                node->children.push_back(root);
                node->splitChild(0,root);

                int i = 0;
                if(node->keys[0] < key)
                    i++;
                node->children[i]->insertNotFull(key);

                root = s;
            }
            else    
                root->insertNotFull(key);
        }
    }   
};

int main()
{
    BTree btree(3);

    return 0;
}