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
        data = c;
        children = new vector<TrieNode*> (26,NULL);
        isWord = false;
    }
};

class Tries
{
    TrieNode *root;
    public:

    Tries()
    {
        root = new TrieNode('\0');
    }

    void insert(string s)
    {
        TrieNode *temp = root;
        int i;
        for( i = 0; i < s.size(); i++)
        {
            if(temp->children->at(s[i]-'a') == NULL)
            {
                TrieNode *node = new TrieNode(s[i]);
                temp->children->at(s[i]-'a') = node;
            }
            temp = temp->children->at(s[i]-'a');
        }
        temp->isWord = true;
    }

    bool search(string s)
    {

    }

    void print(TrieNode *root,string s = "")
    {

        if(root == NULL)
        {
            return;
        }

        if(root->isWord)
            cout << s << endl;


        for(int i = 0;i < 26; i++)
        {
            if(root->children->at(i) != NULL)
            {
                print(root->children->at(i),s+(char)(i+'a'));
            }
        }

    }
    void pt()
    {
        print(root);
    }

};


int main()
{
    Tries trie;
    trie.insert("hello");
    trie.insert("hey");
    trie.insert("poda");
    trie.pt();
    return 0;
}