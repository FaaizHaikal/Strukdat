#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BST_node{
    int data;
    struct BST_node *left, *right;
}Node;

Node *newNode(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->left = temp->right = NULL;

    return temp;
}

Node *insert(Node *root, int value){
    if(root == NULL)
        root = newNode(value);
    else if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}

Node *search(Node *root, int value){
    if(root == NULL || root->data == value)
        return root;
    else if(value < root->data)
        return search(root->left, value);
    else if(value > root->data)
        return search(root->right, value);
}

Node *findParent(Node *root, int value){
    Node *parent = NULL;
    Node *current = root;

    while(current != NULL){
        if(value < current->data){
            parent = current;
            current = current->left;
        }
        else if(value > current->data){
            parent = current;
            current = current->right;
        }
        else
            return parent;
    }
}

void inorder(Node *root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    Node *root = NULL;

    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 13);

    Node *Parent11 = findParent(root, 11);
    printf("Parent of node 11 is %d\n", Parent11->data);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}