#include<stdio.h>
#include<stdlib.h>

// structure of node in LL
struct node {
    int data;
    struct node * next;
};

struct node * head = NULL;

struct node* rev(struct node * head){
    struct node *cur = head;
    struct node *prev = NULL; 
    struct node * nxt = NULL;

    while(cur != NULL){
        nxt = cur->next;
        cur ->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = pre;
    return head;
}

