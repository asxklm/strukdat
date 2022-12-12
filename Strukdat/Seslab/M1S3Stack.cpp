#include <iostream>
using namespace std;

struct Node {
    string data;
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

bool isEmpty(stc* stc) {
    return (stc->_top == NULL);
}

void push(stc* stc, string value) {
    Node* nwNode = new Node;

    if(nwNode) {
        nwNode->data = value;

        if(isEmpty(stc)) nwNode->next = NULL;
        else nwNode->next = stc->_top;

        stc->_top = nwNode;
        stc->_size++;
    }
}

void pop(stc *stc) {
    if(!isEmpty(stc)) {
        Node *temp = stc->_top;
        stc->_top = stc->_top->next;
        free(temp);
        stc->_size--;
    }
}

string top(stc *stc) {
    if(!isEmpty(stc)) {
        return stc->_top->data;
    }
    return 0;
}

void prtStc(stc *stc) {
    Node* current = stc->_top;

    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    stc stc;
    init(&stc);

    push(&stc, "string1");
    push(&stc, "string2");
    push(&stc, "string3");
    push(&stc, "string4");
    pop(&stc);
    cout << top(&stc) << endl;

    prtStc(&stc);

    return 0;
}
