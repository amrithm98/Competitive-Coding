#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:

    char data;
    vector<TrieNode*> *children;
    bool isWord;

    TrieNode(char c)
    {
        children = new vector<TrieNode*>(26,NULL);
        data = c;
        isWord = false;
    }
};

class Trie
{
    TrieNode *root;
    public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(TrieNode *node,string word)
    {
        if(word.size() == 0)
        {
            node->isWord = true;
            return;
        }

        int index = word[0]-'a';
        TrieNode *child;
        if(node->children->at(index) != NULL)
        {
            child = node->children->at(index);
        }
        else
        {
            child = new TrieNode(word[0]);
            node->children->at(index) = child;
        }
        insert(child,word.substr(1));  

    }

    bool search(TrieNode *node,string word)
    {

        if(word.size() == 0)
            return node->isWord;
        
        int index = word[0]-'a';
        if(node->children->at(index) != NULL)
            return search(node->children->at(index),word.substr(1));
        else
            return false;
    }

    void removeWord(TrieNode *node,string word)
    {
        if(word.size() == 0)
        {
            node->isWord = false;
            return;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if(node->children->at(index) != NULL)
        {
            child = node->children->at(index);
            removeWord(child,word.substr(1));
        }
        else
            return;

        if(child->isWord == false)
        {
            for(int i = 0; i < 26; i++)
            {
                if(child->children->at(i) != NULL)
                    return;
            }
            delete child;
            node->children->at(index) = NULL;
        }
    }

    void insert(string word)
    {
        insert(root,word);
    }

    bool search(string word)
    {
        return search(root,word);
    }

    void removeWord(string word)
    {
        removeWord(root,word);
    }
};

int main()
{
    Trie trie;
    trie.insert("hello");
    trie.insert("hey");
    cout << trie.search("hello") << endl;
    cout << trie.search("hey") << endl;
    trie.removeWord("hey");
    cout << trie.search("hey") << endl;

    return 0;
}