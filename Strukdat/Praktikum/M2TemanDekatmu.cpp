#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *NLeft;
    Node *NRight;
};

struct BST {
    Node *_root;
};

void inIt(BST *tree) {
    tree->_root = NULL;
}

bool isEmpty(BST *tree) {
    return (tree->_root == NULL);
}

void inSert(BST *tree, int data) {
    Node *NwNode = new Node;
    NwNode->data = data;
    NwNode->NLeft = NULL;
    NwNode->NRight = NULL;

    if (isEmpty(tree)) {
        tree->_root = NwNode;
    } else {
        Node *current = tree->_root;
        Node *parent = NULL;

        while (current != NULL) {
            parent = current;
            if (data < current->data) {
                current = current->NLeft;
            } else {
                current = current->NRight;
            }
        }

        if (data < parent->data) {
            parent->NLeft = NwNode;
        } else {
            parent->NRight = NwNode;
        }
    }
}

bool checkBST(Node *root, int min, int max) {
    if (root == NULL) {
        return true;
    } else if (root->data < min || root->data > max) {
        return false;
    } else {
        return checkBST(root->NLeft, min, root->data - 1) &&
               checkBST(root->NRight, root->data + 1, max);
    }
}

bool isBST(Node *root) {
    return checkBST(root, -1000000000, 1000000000);
}

void postOrdEr(Node *root) {
    if (root != NULL) {
        postOrdEr(root->NLeft);
        postOrdEr(root->NRight);
        cout << root->data << " ";
    }
}

int main() {
BST tree;
inIt(&tree);

for (int i = 0; i < 20; i++) 
{
        int data;
        cin >> data;
        inSert(&tree, data);
}

if (isBST(tree._root)) {
        cout << "Bisa ini!" << endl;
        postOrdEr(tree._root);
} else {
        cout << "Nggak bisa ini" << endl;
}
return 0;
}
