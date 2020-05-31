#include<stdio.h>
#include<stdlib.h>


struct treeNode{
    int data;
    struct treeNode *left, *right;
};
struct treeNode *root = NULL;



void insert(int data){
    struct treeNode *newNode = (struct treeNode *)malloc(sizeof(struct treeNode));
    struct treeNode * temp = root;
    if(root == NULL){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else {
        while(data < temp->data){
            temp = temp->left;
        }
        newNode->data = data;
        temp->left = newNode;
    }
}

    