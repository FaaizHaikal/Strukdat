#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sum = 0;

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
    if(root == NULL) root = newNode(value);
    else if(value < root->data) root->left = insert(root->left, value);
    else if(value > root->data) root->right = insert(root->right, value);

    return root;
}

int solve(node *root, int tebak){
    if(root == NULL) return 0;

    if(root->left != NULL && root->right != NULL){
        if(root->left->data + root->right->data + root->data == tebak)
            return 1;
    }

    if(root->left != NULL && root->left->left != NULL){
        if(root->left->data + root->left->left->data + root->data == tebak)
            return 1;
    }

    if(root->right != NULL && root->right->right != NULL){
        if(root->right->data + root->right->right->data + root->data == tebak)
            return 1;
    }

    if(root->left != NULL && root->left->right != NULL){
        if(root->left->data + root->left->right->data + root->data == tebak)
            return 1;
    }

    if(root->right != NULL && root->right->left != NULL){
        if(root->right->data + root->right->left->data + root->data == tebak)
            return 1;
    }

    int x = solve(root->left, tebak);
    int y = solve(root->right, tebak);

    if(x == 1 || y == 1)
        return 1;
}

int main(){
    node *root = NULL;
    int t, value;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &value);
        root = insert(root, value);
    }
    int tebak;
    scanf("%d", &tebak);

    if(solve(root, tebak)) printf("ManTap");
    else printf("HAiiyyaAhh SalAhh");
}