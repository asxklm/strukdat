#include <iostream>

using namespace std;

struct Node {
    int id;
    int urgency_level;
    Node* next;
};

struct primeQueue {
    Node* _top;
    unsigned _size;
};

void init(primeQueue* pqueue) {
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool isEmpty(primeQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void push(primeQueue *pqueue, int id, int urgency_level) {
    Node *temp = pqueue->_top;
    Node *nwNode = new Node;
    pqueue->_size++;
    nwNode->id = id;
    nwNode->urgency_level = urgency_level;
    nwNode->next = NULL;

    if (isEmpty(pqueue)) {
        pqueue->_top = nwNode;
        return;
    }

    if (urgency_level > pqueue->_top->urgency_level) {
        nwNode->next = pqueue->_top;
        pqueue->_top = nwNode;
    } else {
        while ( temp->next != NULL && temp->next->urgency_level > urgency_level) {
            temp = temp->next;
        }
        nwNode->next = temp->next;
        temp->next = nwNode;
    }
}

void pop(primeQueue *pqueue)
{
    if (!isEmpty(pqueue)) {
        Node *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        pqueue->_size--;
        free(temp);
    }
}

Node* top(primeQueue *pqueue) {
    if (!isEmpty(pqueue))
        return pqueue->_top;
    else return 0;
}

void printprimeQueue(primeQueue *pqueue) {
    Node* current = pqueue->_top;

    while(current != NULL) {
        cout << current->id << " " << current->urgency_level << endl;
        current = current->next;
    }
}

void dumpprimeQueue(primeQueue *pqueue) {
    Node* current = pqueue->_top;
    cout << endl << "Dump Data : " << endl;
    cout << "size : " << pqueue->_size << endl;
    while(current != NULL) {
        cout << current << " " << current->id << " " << current->urgency_level << " " << current->next << endl;
        current = current->next;
    }
}

void controller(string command, primeQueue* pqueue) {
    if (command == "MASUK") {
        int id, x;
        cin >> id;
        cin >> x;

        push(pqueue, id, x);
    } else if (command == "LAYANI") {
        if (!isEmpty(pqueue)) {
            cout << pqueue->_top->id << endl;
            pop(pqueue);
        } else {
            cout << "HORE" << endl;
        }
    } else if (command == "DUMP") {
        dumpprimeQueue(pqueue);
    } else {
        cout << "TOLONG MASUKKAN QUERY YANG VALID!" << endl;
    }
}

int main()
{
    primeQueue pqueue;
    init(&pqueue);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        controller(command, &pqueue);
    }


    return 0;
}
