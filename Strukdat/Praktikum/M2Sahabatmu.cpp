#include <iostream>
using namespace std;

struct bstNode{
    int key;
    bstNode* kiri;
    bstNode* kanan;
};

struct bst{
    bstNode* root;
    unsigned int size;
};

void init(bst *bst) {
    bst->root = NULL;
    bst->size = 0u;
}

bstNode* bstCreateNode(int value) {
    bstNode *newNode = (bstNode*) malloc(sizeof(bstNode));
    newNode->key = value;
    newNode->kiri = newNode->kanan = NULL;
    return newNode;
}

bstNode* bstInsert(bstNode *root, int value) {
    if (root == NULL) 
        return bstCreateNode(value);

    if (value < root->key)
        root->kiri = bstInsert(root->kiri, value);
    else if (value > root->key)
        root->kanan = bstInsert(root->kanan, value);
    
    return root;
}

bstNode* bstFindMinNode(bstNode *node) {
    bstNode *currNode = node;
    while (currNode && currNode->kiri != NULL)
        currNode = currNode->kiri;
    
    return currNode;
}

bstNode* bstDel(bstNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->kanan = bstDel(root->kanan, value);
    else if (value < root->key) 
        root->kiri = bstDel(root->kiri, value);
    else {
        
        if (root->kiri == NULL) {
            bstNode *kananChild = root->kanan;
            free(root);
            return kananChild;
        }
        else if (root->kanan == NULL) {
            bstNode *kiriChild = root->kiri;
            free(root);
            return kiriChild;
        }

        bstNode *temp = bstFindMinNode(root->kanan);
        root->key     = temp->key;
        root->kanan   = bstDel(root->kanan, temp->key);
    }
    return root;
}

bstNode* bstSearch(bstNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->kiri;
        else if (value > root->key)
            root = root->kanan;
        else
            return root;
    }
    return root;
}

void insert(bst *bst, int value) {
    bst->root = bstInsert(bst->root, value);
    bst->size++;
}

void del(bst *bst, int value) {
    bst->root = bstDel(bst->root, value);
    bst->size--;
}

void changeRoot(bst *bst, int n){
    bst->root->key = n;
}

void bstPreorder(bstNode *root) {
    if (root) {
        cout << root->key << " ";
        bstPreorder(root->kiri);
        bstPreorder(root->kanan);
    }
}

void preorder(bst *bst) {
    bstPreorder(bst->root);
}

int main() {
    int a = 0;
    bst set;
    init(&set);
    int t;
    cin >> t;
    int rt;
    cin >> rt;
    insert(&set, rt);
    t--;
    while(t--){
        int n;
        cin >> n;
        if(n > a && n < rt) a = n;
        insert(&set, n);
    }
    del(&set, a);
    changeRoot(&set, a);
    preorder(&set);

    return 0;
}
