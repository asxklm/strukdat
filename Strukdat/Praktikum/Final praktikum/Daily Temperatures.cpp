#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Nodes {
    int num;
    Nodes *next;
};

struct List{
    Nodes *head;
    Nodes *tail;
};
Nodes *newnode, *curr, *temp, *del, *curt;

void init(List *list){
    list->head = NULL;
    list->tail = NULL;
}

bool check(List *list){
    curr = list->head->next;
    temp = list->head;
    while(curr != NULL){
        if(temp->num > curr->num){
            curr = curr->next;
        }
        else{
            break;
        }
    }
    if(curr == NULL){
        return true;
    }
    else{
        return false;
    }
}

void AddBack(List *list, int num){
    Nodes *newnode = new Nodes;
    newnode->num = num;
    if(list->head == NULL){
        list->head = newnode;
        list->tail = newnode;
        list->head->next = list->tail;
    }
    else{
        newnode->next = NULL;
        list->tail->next = newnode;
        list->tail = newnode;
    }
}

void delFirst(List *list){
    del = list->head;
    list->head = list->head->next;
    delete del;
}


void printRes(List *list){
    curr = list->head->next;
    curt = list->head->next;
    del = curr->next;
    temp = list->head;
    int now = 1;

    // if(curr->next == NULL){
    //     cout << "letsgo!! nul";
    //      cout << endl;
    // }
    if(temp->num < curr->num){
        cout << now << " " << curr->num;
        cout << endl;
    }
    
    else if (check(list) == false){
        curr = list->head->next;
        while(curt != NULL){
            if(temp->num > curt->num){
                now++;
            }
            else{
                break;
            }
            curt = curt->next;
        }
        cout << now << " ";
        while(curr != NULL){
            if(temp->num > curr->num){
                cout << curr->num << " ";
            }
            if(temp->num < curr->num){
                    cout << curr->num << " ";
                    break;
                }
            // if(curr->next == NULL){
            //     break;
            // }
            curr = curr->next;
        }
        cout << endl;
    }
        else if(check(list) == true){
            cout << "letsgo!!";
            cout << endl;
        }
}
//1 2 3 4 5
int main(){
    List list;
    int max, inp;
    init(&list);
    cin >> max;
    if(max >= 1 && max <= 10){
        for(int i = 0; i < max; i++){
            cin >> inp;
            if(inp >= 30 && inp <= 100){
                AddBack(&list, inp);
            }
        }
    }
    for(int j = 0; j < max-1; j++){
        printRes(&list);
        delFirst(&list);
    }
    cout << "letsgo!!";
}