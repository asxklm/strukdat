#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct avl {
    struct avl* left;
    struct avl* right;
    int key;
    struct avl* par;
    int height;
};
 
void Updateheight(struct avl* root)
{
    if (root != NULL) {
        int val = 1;
 
        if (root->left != NULL)
            val = root->left->height + 1;
 
        if (root->right != NULL)
            val = max(
                val, root->right->height + 1);
        
        root->height = val;
    }
}
 
struct avl* LLR(
    struct avl* root)
{
    struct avl* tmpnode = root->left;
 
    root->left = tmpnode->right;
 
    if (tmpnode->right != NULL)
        tmpnode->right->par = root;
 
    tmpnode->right = root;
 
    tmpnode->par = root->par;
 
    root->par = tmpnode;
 
    if (tmpnode->par != NULL
        && root->key < tmpnode->par->key) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }
 
    root = tmpnode;

    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);
 
    return root;
}
 
struct avl* RRR(
    struct avl* root)
{
    struct avl* tmpnode = root->right;
 
    root->right = tmpnode->left;
 
    if (tmpnode->left != NULL)
        tmpnode->left->par = root;

    tmpnode->left = root;
 
    tmpnode->par = root->par;
 
    root->par = tmpnode;
 
    if (tmpnode->par != NULL
        && root->key < tmpnode->par->key) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }
 
    root = tmpnode;

    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);
 
    return root;
}
 
struct avl* LRR(
    struct avl* root)
{
    root->left = RRR(root->left);
    return LLR(root);
}
 
struct avl* RLR(
    struct avl* root)
{
    root->right = LLR(root->right);
    return RRR(root);
}
 
struct avl* Insert(
    struct avl* root,
    struct avl* parent,
    int key)
{
 
    if (root == NULL) {
        root = new struct avl;
        if (root == NULL) {
            cout << "Error in memory" << endl;
        }
        else {
            root->height = 1;
            root->left = NULL;
            root->right = NULL;
            root->par = parent;
            root->key = key;
        }
    }
 
    else if (root->key > key) {
        root->left = Insert(root->left,
                            root, key);
 
        int first = 0;
        int second = 0;
 
        if (root->left != NULL)
            first = root->left->height;
 
        if (root->right != NULL)
            second = root->right->height;
 
        if (abs(first
                - second)
            == 2) {
 
            if (root->left != NULL && key < root->left->key) {
                root = LLR(root);
            }
            else {
                root = LRR(root);
            }
        }
    }
 
    else if (root->key < key) {
        root->right = Insert(root->right, root, key);
 
        int first = 0;
        int second = 0;
 
        if (root->left != NULL)
            first = root->left->height;
 
        if (root->right != NULL)
            second = root->right->height;
 
        if (abs(first
                - second)
            == 2) {
            if (root->right != NULL
                && key < root->right->key) {
                root = RLR(root);
            }
            else {
                root = RRR(root);
            }
        }
    }
    Updateheight(root);
    return root;
}
 
// Function to find a key in AVL tree
bool src(
    struct avl* root, int key)
{
    if (root == NULL)
        return false;
 
    else if (root->key == key)
        return true;
 
    else if (root->key > key) {
        bool val = src(root->left, key);
        return val;
    }
    else {
        bool val = src(root->right, key);
        return val;
    }
}
 

int main()
{
    struct avl* root;
    root = NULL;
    
    int N;
    cin >> N;
    
    // Function call to insert the nodes
    int i, value, search;
    for(i = 0; i < N; i++){
        cin >> value;
        root = Insert(root, NULL, value);
    }
 
    // Function call to search for a node
    cin >> search;
    bool found = src(root, search);
    if (found)
        cout << "value found";
    else
        cout << "value not found";
 
    return 0;
}
