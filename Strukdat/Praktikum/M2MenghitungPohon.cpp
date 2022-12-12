#include <iostream>
#include <stdlib.h>

using namespace std;

struct BSTNode
{
    BSTNode *left, *right;
    int key;
};

struct BST
{
    BSTNode *_root;
    unsigned int _size;

    void init()
    {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        BSTNode *temp = SrcNode(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!find(value))
        {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = RemoveNode(_root, value);
            _size--;
        }
    }

    void print()
    {
        __print(_root);
    }

    BSTNode *__insert(BSTNode *root, int value)
    {
        if (root == NULL)
        {
            BSTNode *temp = new BSTNode;
            temp->key = value;
            temp->left = temp->right = NULL;
            return temp;
        }

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    BSTNode *SrcNode(BSTNode *root, int value)
    {
        if (root == NULL || root->key == value)
            return root;

        if (value < root->key)
            return SrcNode(root->left, value);
        else
            return SrcNode(root->right, value);
    }

    BSTNode *__minValueNode(BSTNode *root)
    {
        BSTNode *current = root;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    BSTNode *RemoveNode(BSTNode *root, int value)
    {
        if (root == NULL)
            return root;

        if (value < root->key)
            root->left = RemoveNode(root->left, value);
        else if (value > root->key)
            root->right = RemoveNode(root->right, value);
        else
        {
            if (root->left == NULL)
            {
                BSTNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                BSTNode *temp = root->left;
                delete root;
                return temp;
            }

            BSTNode *temp = __minValueNode(root->right);
            root->key = temp->key;
            root->right = RemoveNode(root->right, temp->key);
        }
        return root;
    }

    void __print(BSTNode *root)
    {
        if (root)
        {
            __print(root->left);
            cout << root->key << " ";
            __print(root->right);
        }
    }
};

int main()
{
    BST bst;
    bst.init();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bst.insert(x);
    }

    cout << bst._size << endl;

    return 0;
}
