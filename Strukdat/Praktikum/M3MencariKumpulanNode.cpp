#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    struct Node* Nleft, *Nright;
    int height;
    int desc;
};
 
int height(struct Node* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
struct Node* NWnode(int key)
{
    struct Node* node = new Node();
    node->key = key;
    node->Nleft = NULL;
    node->Nright = NULL;
    node->height = 1;
    node->desc = 0;
    return (node);
}

struct Node* NrightRotate(struct Node* y)
{
    struct Node* x = y->Nleft;
    struct Node* T2 = x->Nright;

    x->Nright = y;
    y->Nleft = T2;
    
    y->height = max(height(y->Nleft), height(y->Nright)) + 1;
    x->height = max(height(x->Nleft), height(x->Nright)) + 1;
 
    int val = (T2 != NULL) ? T2->desc : -1;
    y->desc = y->desc - (x->desc + 1) + (val + 1);
    x->desc = x->desc - (val + 1) + (y->desc + 1);
 
    return x;
}
 
struct Node* NleftRotate(struct Node* x)
{
    struct Node* y = x->Nright;
    struct Node* T2 = y->Nleft;
 
    y->Nleft = x;
    x->Nright = T2;
 
    x->height = max(height(x->Nleft), height(x->Nright)) + 1;
    y->height = max(height(y->Nleft), height(y->Nright)) + 1;
 
    int val = (T2 != NULL) ? T2->desc : -1;
    x->desc = x->desc - (y->desc + 1) + (val + 1);
    y->desc = y->desc - (val + 1) + (x->desc + 1);
 
    return y;
}
 
int getBalance(struct Node* N)
{
    if (N == NULL)
        return 0;
    return height(N->Nleft) - height(N->Nright);
}
 
struct Node* insert(struct Node* node, int key)
{
    if (node == NULL)
        return (NWnode(key));
 
    if (key < node->key) {
        node->Nleft = insert(node->Nleft, key);
        node->desc++;
    }
 
    else if (key > node->key) {
        node->Nright = insert(node->Nright, key);
        node->desc++;
    }
 
    else 
        return node;
 
    node->height = 1 + max(height(node->Nleft),
                        height(node->Nright));
 
    int balance = getBalance(node);
 
    if (balance > 1 && key < node->Nleft->key)
        return NrightRotate(node);
 
    if (balance < -1 && key > node->Nright->key)
        return NleftRotate(node);
 
    if (balance > 1 && key > node->Nleft->key) {
        node->Nleft = NleftRotate(node->Nleft);
        return NrightRotate(node);
    }
    
    if (balance < -1 && key < node->Nright->key) {
        node->Nright = NrightRotate(node->Nright);
        return NleftRotate(node);
    }
    return node;
}
 
struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    while (current->Nleft != NULL)
        current = current->Nleft;
 
    return current;
}
 
struct Node* delNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;
 
    if (key < root->key) {
        root->Nleft = delNode(root->Nleft, key);
        root->desc = root->desc - 1;
    }
 
    else if (key > root->key) {
        root->Nright = delNode(root->Nright, key);
        root->desc = root->desc - 1;
    }
 
    else {
        if ((root->Nleft == NULL) || (root->Nright == NULL)) {
 
            struct Node* temp = root->Nleft ? root->Nleft : root->Nright;
            
            if (temp == NULL) {
                temp = root;
                root = NULL;
                free(temp);
 
            }
            else
            {
                *root = *temp; 
                free(temp);
            }
        } else {
            struct Node* temp = minValueNode(root->Nright);
 
            root->key = temp->key;
 
            root->Nright = delNode(root->Nright, temp->key);
            root->desc = root->desc - 1;
        }
    }
 
    if (root == NULL)
        return root;
 
    root->height = 1 + max(height(root->Nleft), height(root->Nright));
 
    int balance = getBalance(root);
    
    if (balance > 1 && getBalance(root->Nleft) >= 0)
        return NrightRotate(root);
 
    if (balance > 1 && getBalance(root->Nleft) < 0) {
        root->Nleft = NleftRotate(root->Nleft);
        return NrightRotate(root);
    }
 
    if (balance < -1 && getBalance(root->Nright) <= 0)
        return NleftRotate(root);
 
    if (balance < -1 && getBalance(root->Nright) > 0) {
        root->Nright = NrightRotate(root->Nright);
        return NleftRotate(root);
    }
 
    return root;
}
 
int CountGreater(struct Node* root, int x)
{
    int res = 0;
    while (root != NULL) {
 
        int desc = (root->Nright != NULL) ?
                root->Nright->desc : -1;
 
        if (root->key > x) {
            res = res + desc + 1 + 1;
            root = root->Nleft;
        } else if (root->key < x)
            root = root->Nright;
        else {
            res = res + desc + 1;
            break;
        }
    }
    return res;
}
 

int main()
{
    struct Node* root = NULL;
    
    int N;
    cin >> N;
    
    int i, value, count;
    for(i = 0; i < N; i++){
        cin >> value;
        root = insert(root, value);
    }
    
    cin >> count;
    cout << CountGreater(root, count);
    
    return 0;
}

