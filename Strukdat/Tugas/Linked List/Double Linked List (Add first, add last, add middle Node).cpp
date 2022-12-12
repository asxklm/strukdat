#include <stdio.h>  
   
//Represent a node of the doubly linked list  
  
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};      
   
int size = 0;  
//Represent the head and tail of the doubly linked list  
struct node *head, *tail = NULL;  
   
//addNode() will add a node to the list  
void addNode(int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
      
    //If list is empty  
    if(head == NULL) {  
        //Both head and tail will point to newNode  
        head = tail = newNode;  
        //head's previous will point to NULL  
        head->previous = NULL;  
        //tail's next will point to NULL, as it is the last node of the list  
        tail->next = NULL;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode's previous will point to tail  
        newNode->previous = tail;  
        //newNode will become new tail  
        tail = newNode;  
        //As it is last node, tail's next will point to NULL  
        tail->next = NULL;  
    }  
    //Size will count the number of nodes present in the list  
    size++;  
}  
   
//addInMid() will add a node to the middle of the list  
void addInMid(int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
      
    //If list is empty  
    if(head == NULL) {  
        //Both head and tail will point to newNode  
        head = tail = newNode;  
        //head's previous will point to NULL  
        head->previous = NULL;  
        //tail's next point to NULL, as it is the last node of the list  
        tail->next = NULL;  
    }  
    else {  
        //current will point to head  
        struct node *current = head, *temp = NULL;  
          
        //Store the mid position of the list  
        int mid = (size % 2 == 0) ? (size/2) : ((size+1)/2);      
          
        //Iterate through list till current points to mid position  
        for(int i = 1; i < mid; i++){  
            current = current->next;  
        }  
          
        //Node temp will point to node next to current  
        temp = current->next;  
        temp->previous = current;  
          
        //newNode will be added between current and temp  
        current->next = newNode;  
        newNode->previous = current;  
        newNode->next = temp;  
        temp->previous = newNode;  
    }  
    size++;  
}  
   
//display() will print out the nodes of the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  
        //Prints each node by incrementing pointer.  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{  
    //Add nodes to the list  
    addNode(1);  
    addNode(2);  
      
    printf("Original list: \n");  
    display();  
      
    //Adding node '3' in the middle  
    addInMid(3);  
    printf( "Updated List: \n");  
    display();  
      
    //Adding node '4' in the middle  
    addInMid(4);  
    printf("Updated List: \n");  
    display();  
      
    //Adding node '5' in the middle  
    addInMid(5);  
    printf("Updated List: \n");  
    display();  
   
    return 0;  
}  
