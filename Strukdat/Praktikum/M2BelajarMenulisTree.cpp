#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    BSTNode *NLeft, *NRight;
    int key;
};


struct BST {
    BSTNode *_root;
    unsigned int _size;
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = SrcNode(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = InNode(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = RemoveNode(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

private:

    BSTNode* AddNode(int value) {
        BSTNode *newNode = new BSTNode;
        newNode->key = value;
        newNode->NLeft = newNode->NRight = NULL;
        return newNode;
    }
    
    BSTNode* SrcNode(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->NLeft;
            else if (value > root->key)
                root = root->NRight;
            else
                return root;
        }
        return root;
    }

    BSTNode* InNode(BSTNode *root, int value) {
        if (root == NULL)
            return AddNode(value);
        
        if (value < root->key)
            root->NLeft = InNode(root->NLeft, value);
        else if (value > root->key)
            root->NRight = InNode(root->NRight, value);
        
        return root;
    }

    BSTNode* MinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->NLeft != NULL)
            currNode = currNode->NLeft;
        
        return currNode;
    }

    BSTNode* RemoveNode(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->NRight = RemoveNode(root->NRight, value);
        else if (value < root->key) 
            root->NLeft = RemoveNode(root->NLeft, value);
        else {

            if (root->NLeft == NULL) {
                BSTNode *NRightChild = root->NRight;
                free(root);
                return NRightChild;
            }
            else if (root->NRight == NULL) {
                BSTNode *NLeftChild = root->NLeft;
                free(root);
                return NLeftChild;
            }

            BSTNode *temp = MinNode(root->NRight);
            root->key     = temp->key;
            root->NRight   = RemoveNode(root->NRight, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->NLeft);
            printf("%d ", root->key);
            __inorder(root->NRight);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->NLeft);
            __postorder(root->NRight);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->NLeft);
            __preorder(root->NRight);
        }
    }
};

int main(int argc, char const *argv[]){
    BST set;
    
    set.init();
        int n;
    int o;
    cin >> o;
    for (int i = 0; i < o; i++) {
            cin >> n;
            if (n == 0) {
                break;
            }
            set.insert(n);

    }
    cout<<"InOrder"<<endl;
    set.traverseInorder();

    cout<<"\nPreOrder"<<endl;
    set.traversePreorder();
    
    cout<<"\nPostOrder"<<endl;
    set.traversePostorder();

    return 0;
}
