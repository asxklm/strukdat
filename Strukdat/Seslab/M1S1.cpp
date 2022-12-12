#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct stc {
    Node* _top;
    unsigned _size;
};

void init(stc* stc) {
    stc->_top = NULL;
    stc->_size = 0;
}

bool isFree(stc* stc) {
    return (stc->_top == NULL);
}

void push(stc* stc, int value) {
    Node* nwnode = new Node;
    if(nwnode) {
        nwnode->data = value;

        if(isFree(stc)) nwnode->next = NULL;
        else nwnode->next = stc->_top;

        stc->_top = nwnode;
        stc->_size++;
    }
}

void pop(stc *stc) {
    if(!isFree(stc)) {
        Node *temp = stc->_top;
        stc->_top = stc->_top->next;
        free(temp);
        stc->_size--;
    }
}

int top(stc *stc) {
    if(!isFree(stc)) {
        return stc->_top->data;
    }
    return 0;
}

void printstc(stc *stc) {
    Node* current = stc->_top;

    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

Node* findlowestNode(stc* stc) {
    Node* current = stc->_top;
    Node* lowest = current;
    
    while(current != NULL) {
        if(current->data < lowest->data) {
            lowest = current;
        }
        current = current->next;
    }

    return lowest;
}

int main()
{
    stc stc;
    init(&stc);

    push(&stc, 3);
    push(&stc, 2);
    push(&stc, 8);
    push(&stc, -5);
    push(&stc, 4);
    push(&stc, 2);
    push(&stc, 1);
    pop(&stc);
    Node* lowest = findlowestNode(&stc);
    cout << lowest->data << endl;
    
    cout << top(&stc) << endl;

    printstc(&stc);

    return 0;
}
