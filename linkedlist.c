#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
int count = 0;
struct node * head = NULL;

void insert_at_begin(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    count++;
    if(head == NULL){
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}


void insert_at_end(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    count++;
    struct node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    
}

void delete_at_begin(){
    if(head == NULL){
        printf("Linked List is empty");
    }
    else{
        count --;
        head = head->next;
    }
    
}

void delete_from_end(){
    struct node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
}

void traverse(){
    struct node * temp;
    temp = head;
    if(temp == NULL){
        printf("Linked list empty");
    }
    else{
        while(temp->next!= NULL){
            printf("%d->" ,temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}






int main(){

    insert_at_begin(10);
    insert_at_begin(20);
    insert_at_end(30);
    traverse();
    delete_at_begin();
    // delete_at_begin();
    // delete_at_begin();
    delete_from_end();
    traverse();
    return 0;
}