#include <iostream>
using namespace std;

struct Node {
    string data;
    struct Node *next, *prev;
};

struct Deque {
    Node *_head, *_tail;
    unsigned _size;
};

void init(Deque* deque) {
    deque->_head = NULL;
    deque->_tail = NULL;
    deque->_size = 0;
}

bool isFree(Deque *deque) {
    return (deque->_head == NULL && deque->_tail == NULL);
}

void pushFront(Deque *deque, string value) {
    Node *nwNode = new Node;
    if(nwNode) {
        deque->_size++;

        nwNode->data = value;
        
        if(isFree(deque)) {
            deque->_head = nwNode;
            deque->_tail = nwNode;
            return;
        }

        nwNode->next = deque->_head;
        deque->_head->prev = nwNode;
        deque->_head = nwNode;
    }
}

void pushBack(Deque* deque, string value) {
    Node* nwNode = new Node;
    if(nwNode) {
        deque->_size++;

        nwNode->data = value;

        if(isFree(deque)) {
            deque->_head = nwNode;
            deque->_tail = nwNode;
            return;
        }

        deque->_tail->next = nwNode;
        nwNode->prev = deque->_tail;
        deque->_tail = nwNode;
    }
}

string front(Deque* deque) {
    if(isFree(deque)) {
        return deque->_head->data;
    }
    return 0;
}

string back(Deque* deque) {
    if(isFree(deque)) {
        return deque->_tail->data;
    }
    return 0;
}

void popFront(Deque *deque)
{
    if (!isFree(deque)) {
        Node *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void popBack(Deque *deque)
{
    if (!isFree(deque)) {
        Node *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void printDeque(Deque *deque) {
    Node* current = deque->_head;

    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    Deque deque;
    init(&deque);

    pushFront(&deque, "string1");
    pushFront(&deque, "string2");
    pushBack(&deque, "string3");
    pushBack(&deque, "string4");
    popFront(&deque);
    popBack(&deque);
    printDeque(&deque);

    return 0;
}
