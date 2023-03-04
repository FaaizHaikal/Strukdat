#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bst_node{
    int data;
    struct bst_node *left, *right;
}node;

node *newNode(int value){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert(node *root, int value){
    if(root == NULL)
        root = newNode(value);
    else if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node *root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    node *root = NULL;
    int n;
    scanf("%d", &n);
    int value;
    while(n--){
        scanf("%d", &value);
        root = insert(root, value);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}

