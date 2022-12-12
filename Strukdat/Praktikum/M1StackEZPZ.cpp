#include <iostream>
using namespace std;

struct Node{
    int n;
    Node* next;
};

struct Stack{
    Node* top;
    unsigned size;
};

void init(Stack* stack){
    stack->top = NULL;
    stack->size = 0;
}

bool isFree(Stack* stack){
    return (stack->top == NULL);
}

int top(Stack *stack){
    if(!isFree(stack)) {
        return stack->top->n;
    }
    return 0;
}

void printTop(Stack *stack){
    if(!isFree(stack)) cout << stack->top->n << endl; 
    else cout << "gadak!" << endl;
}

void add(Stack* stack, int n){
    Node* nwNode = new Node;
    if(nwNode) {
        nwNode->n = n;

        if(isFree(stack)) nwNode->next = NULL;
        else nwNode->next = stack->top;

        stack->top = nwNode;
        stack->size++;
    }
}

void del(Stack *stack){
    if(!isFree(stack)) {
        Node *dele = stack->top;
        stack->top = stack->top->next;
        free(dele);
        stack->size--;
    }
}

int main(){
    Stack stack;
    init(&stack);
    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
        int com;
        cin >> com;
        if(com == 1){
            int n;
            cin >> n;
            add(&stack, n);
        }
        else if(com == 2) del(&stack);
        else{
            printTop(&stack);
        }
    }
    return 0;
}
