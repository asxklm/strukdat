#include <iostream>
#include <string>

using namespace std;

struct stcNode{
    int value;
    stcNode *next;
};

struct stack{
    stcNode *_top;
    unsigned _size;
};

void stackInit(stack *stack);
bool isEmpty(stack *stack);
void stackPush(int value, stack *stack);
void stackPop(stack *stack);

stcNode *smlNode(stack *stack){
    stcNode *curr = stack->_top;
    stcNode *smallest = curr;
    while(curr != NULL){
        if(curr->value < smallest->value){
            smallest = curr;
        }  
        curr = curr->next;
    }
    return smallest;
}

int main(){
    stack stack;
    stackInit(&stack);

    int T, i, j, count = 0;
    cin >> T;
    
    string str[T];
    int value[T];
    
    for(i = 0; i < T; i++){
        cin >> str[i];
        if(str[i] == "PULANG!"){
            stcNode *smallest = smlNode(&stack);
            for(j = 0; j < count; j++){
                if(smallest->value == value[j]){
                    cout << str[j] << endl;
                }
            }
            continue;
        }
        cin >> value[i];
        stackPush(value[i], &stack);
        count++;
    }

    return 0;
}

void stackInit(stack *stack){
    stack->_size = 0;
    stack->_top = NULL;
}

bool isEmpty(stack *stack){
    return (stack->_top == NULL);
}

void stackPush(int value, stack *stack){
    stcNode *newnode = new stcNode();
    if(newnode){
        newnode->value = value;

        if(isEmpty(stack)){
            newnode->next = NULL;
        }
        else{
            newnode->next = stack->_top;
        }

        stack->_top = newnode;
        stack->_size++;
    }
}

void stackPop(stack *stack){
    if(!isEmpty(stack)){
        stcNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}
