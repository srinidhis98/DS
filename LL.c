#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};
struct node *head = NULL;
int count = 0;


void insertBeg(int data){
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    if(head == NULL){
        head = newNode;
        newNode->next = NULL;
// printf("%d", temp->data);
    }
    else {
    newNode->next = head;
    head = newNode;
    }
    count++;
    // printf("%d", temp->data);
}

void insertEnd(int data){
    struct node *temp = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;      
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    count ++;
}

void insertPos(int data, int pos){
    struct node * temp = head;
    if(head != NULL){
        for(int i=1; i<pos; i++){
            temp = temp->next;
        }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    }
    count++;
}

struct node * deleteBeg(){
    if(count != 0){
        struct node * temp = head;
        head = temp->next;
        free(temp);
    }
    count --;
    return head;
}


struct node* deleteEnd(){
    if(count != 0){
        struct node * temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    count --;
    return head;
}

struct node* deletePos(int pos){
    struct node * temp = head;
    if(head != NULL){
        for(int i=1; i<pos-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next);
    }
    count --;
    return head;
}

void reverse(){
    struct node * cur = head;
    struct node * next = head;
    struct node * pre = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head = pre;
}


void reverse_recurse(struct node *p){
    if(p->next == NULL){
        head = p;
        return;
    }
    reverse_recurse(p->next);
    struct node * q = p->next;
    q->next = p;
    p->next = NULL;
}

void mid_ele(){
    struct node * fast = head;
    struct node * slow = head;
    while(fast->next!= NULL){
        if(fast ->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        else{
            fast = fast->next;
        }
        
    }
    printf("%d\n", slow->data);
}




void print_LL(){
    struct node * temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    // printf("enter the numbers to be inserted\n");
    // int x,n;
    // scanf("%d", &n);

    insertBeg(10);
    print_LL();
    insertEnd(20);
    print_LL();
    insertBeg(30);
    print_LL();
    insertEnd(40);
    print_LL();
    insertPos(50,2);
    print_LL();
    // head = deleteBeg();
    // print_LL();
    // head = deleteEnd();
    // print_LL();
    head = deletePos(1);
    print_LL();
    reverse();
    print_LL();
    reverse_recurse(head);
    print_LL();
    mid_ele();
    // print_LL();
    return 0;
}

