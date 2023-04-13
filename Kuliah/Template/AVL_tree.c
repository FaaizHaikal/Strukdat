#include <stdio.h>
#include <stdlib.h>

typedef struct AVL_node{
    int data;
    int height;
    struct AVL_node *left, *right;
}Node;

Node *newNode(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->height = 1;
    temp->left = temp->right = NULL;

    return temp;
}

int getHeight(Node *node){
    if(node == NULL)
        return 0;
    return node->height;
}

int balanceFactor(Node *node){
    if(node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node *rightRotate(Node *pivotNode){
    
}
Node *insert(int value)