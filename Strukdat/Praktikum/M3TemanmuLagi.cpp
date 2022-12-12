#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *nLeft,*nRight;
    int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

 
struct LLNode{
    int key;
    struct LLNode *prev, *next;
};
 
LLNode* newLLNode(int key)
{
    LLNode* temp = new LLNode;
    temp->key = key;
    temp->prev = temp->next = NULL;
    return temp;
}

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
    newNode->nLeft = newNode->nRight = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->nLeft;
        else if (value > root->data)
            root = root->nRight;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _nRightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->nLeft;
    pivotNode->nLeft=newParrent->nRight;
    newParrent->nRight=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->nLeft),
                      _getHeight(pivotNode->nRight))+1;
    newParrent->height=_max(_getHeight(newParrent->nLeft),
                       _getHeight(newParrent->nRight))+1;
    
    return newParrent;
}

AVLNode* _nLeftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->nRight;
    pivotNode->nRight=newParrent->nLeft;
    newParrent->nLeft=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->nLeft),
                      _getHeight(pivotNode->nRight))+1;
    newParrent->height=_max(_getHeight(newParrent->nLeft),
                       _getHeight(newParrent->nRight))+1;
    
    return newParrent;
}

AVLNode* _nLeftCaseRotate(AVLNode* node){
    return _nRightRotate(node);
}

AVLNode* _nRightCaseRotate(AVLNode* node){
    return _nLeftRotate(node);
}

AVLNode* _nLeftRightCaseRotate(AVLNode* node){
    node->nLeft=_nLeftRotate(node->nLeft);
    return _nRightRotate(node);
}

AVLNode* _nRightLeftCaseRotate(AVLNode* node){
    node->nRight=_nRightRotate(node->nRight);
    return _nLeftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->nLeft)-_getHeight(node->nRight);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {
    
    if(node==NULL)
        return _avl_createNode(value);
    if(value < node->data)
        node->nLeft = _insert_AVL(avl,node->nLeft,value);
    else if(value > node->data)
        node->nRight = _insert_AVL(avl,node->nRight,value);
    
    node->height= 1 + _max(_getHeight(node->nLeft),_getHeight(node->nRight)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->nLeft->data) 
        return _nLeftCaseRotate(node);
    if(balanceFactor > 1 && value > node->nLeft->data)  
        return _nLeftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->nRight->data)
        return _nRightCaseRotate(node);
    if(balanceFactor < -1 && value < node->nRight->data)
        return _nRightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->nLeft != NULL)
        currNode = currNode->nLeft;
    return currNode;
}

AVLNode* _remove_AVL(AVLNode* node,int value){
    if(node==NULL)
        return node;
    if(value > node->data)
        node->nRight=_remove_AVL(node->nRight,value);
    else if(value < node->data)
        node->nLeft=_remove_AVL(node->nLeft,value);
    else{
        AVLNode *temp;
        if((node->nLeft==NULL)||(node->nRight==NULL)){
            temp=NULL;
            if(node->nLeft==NULL) temp=node->nRight;  
            else if(node->nRight==NULL) temp=node->nLeft;
            
            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;   
            
            free(temp);
        }
        else{
            temp = _findMinNode(node->nRight);
            node->data=temp->data;
            node->nRight=_remove_AVL(node->nRight,temp->data);
        }    
    }

    if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->nLeft),_getHeight(node->nRight))+1;

    int balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->nLeft)>=0) 
        return _nLeftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->nLeft)<0) 
        return _nLeftRightCaseRotate(node);
  
    if(balanceFactor < -1 && _getBalanceFactor(node->nRight)<=0) 
        return _nRightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->nRight)>0) 
        return _nRightLeftCaseRotate(node);
    
    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }

}

void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

void preorder(AVLNode *root) {
    if (root) {
        preorder(root->nLeft);
        printf("%d ", root->data);
        preorder(root->nRight);
    }
}

void verticalSumDLLUtil(AVLNode *root, LLNode *sumNode)
{
    sumNode->key = sumNode->key + root->data;
 
    if(root->nLeft)
    {
        if(sumNode->prev == NULL)
        {
            sumNode->prev = newLLNode(0);
            sumNode->prev->next = sumNode;
        }
        verticalSumDLLUtil(root->nLeft, sumNode->prev);
    }
 
    if(root->nRight)
    {
        if(sumNode->next == NULL)
        {
            sumNode->next = newLLNode(0);
            sumNode->next->prev = sumNode;
        }
        verticalSumDLLUtil(root->nRight, sumNode->next);
    }
}
 
void verticalSumDLL(AVLNode* root)
{
    LLNode* sumNode = newLLNode(0);
 
    verticalSumDLLUtil(root, sumNode);
 
    while(sumNode->prev != NULL){
        sumNode = sumNode->prev;
    }
 
    while(sumNode != NULL){
        cout << sumNode->key <<" ";
        sumNode = sumNode->next;
    }
}
 
int main(){
    AVL avlku;
    avl_init(&avlku);
    
    int x, inp;
    char str[50];
    scanf("%d", &x);

    while(x--){
    scanf("%s", str);   
    if(!strcmp(str, "insert")){
        
        scanf("%d", &inp);
        avl_insert(&avlku, inp);
    }else{
        verticalSumDLL(avlku._root);
        printf("\n");
    }
}

}
