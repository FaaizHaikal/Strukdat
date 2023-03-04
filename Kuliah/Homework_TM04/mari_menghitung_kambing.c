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

int ans(node *root, int tebak, int visited){
    if(root == NULL || visited > 3) return 0;

    if(root->data == tebak && visited == 3) return 1;
    else if(tebak < root->data) sum += ans(root->left, tebak - root->data, visited+1);
    else sum += ans(root->right, tebak - root->data, visited+1);
    
    sum += ans(root->right, tebak, visited);
    sum += ans(root->left, tebak, visited);
    return sum;

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

    if(ans(root, tebak, 1)) printf("ManTap");
    else printf("HAiiyyaAhh SalAhh");
}