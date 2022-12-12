#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

struct PrimeQueue {
    Node* _top;
    unsigned _size;
};

void init(PrimeQueue* pqueue) {
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool isEmpty(PrimeQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void push(PrimeQueue *pqueue, string value) {
    Node *temp = pqueue->_top;
    Node *nwNode = new Node;
    nwNode->data = value;
    nwNode->next = NULL;

    if (isEmpty(pqueue)) {
        pqueue->_top = nwNode;
        return;
    }

    if (value.compare(pqueue->_top->data) < 0) {
        nwNode->next = pqueue->_top;
        pqueue->_top = nwNode;
    } else {
        while ( temp->next != NULL && (temp->next->data).compare(value) < 0) {
            temp = temp->next;
        }
        nwNode->next = temp->next;
        temp->next = nwNode;
    }
}

void pop(PrimeQueue *pqueue)
{
    if (!isEmpty(pqueue)) {
        Node *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

string top(PrimeQueue *pqueue) {
    if (!isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

void prtPrimeQueue(PrimeQueue *pqueue) {
    Node* current = pqueue->_top;

    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    PrimeQueue pqueue;
    init(&pqueue);

    push(&pqueue, "A");
    prtPrimeQueue(&pqueue);
    cout << endl;
    
    push(&pqueue, "C");
    prtPrimeQueue(&pqueue);
    cout << endl;

    push(&pqueue, "B");
    prtPrimeQueue(&pqueue);
    cout << endl;

    push(&pqueue, "Z");
    prtPrimeQueue(&pqueue);
    cout << endl;

    push(&pqueue, "B");
    prtPrimeQueue(&pqueue);
    cout << endl;

    push(&pqueue, "D");
    prtPrimeQueue(&pqueue);
    cout << endl;

    push(&pqueue, "F");
    prtPrimeQueue(&pqueue);

    return 0;
}
