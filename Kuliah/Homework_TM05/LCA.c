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

node *search(node *root, int value){
    if(root == NULL || root->data == value)
        return root;
    else if(value < root->data)
        return search(root->left, value);
    else if(value > root->data)
        return search(root->right, value);
}

int findLCA(node *root, int v1, int v2){
    if(root == NULL)
        return 0;
    if(root->data > v1 && root->data > v2)
        findLCA(root->left, v1, v2);
    else if(root->data < v1 && root->data < v2)
        findLCA(root->right, v1, v2);
    else
        return root->data;  
}

int main(){
    node *root = NULL;
    int query, value;
    scanf("%d", &query);
    while(query--){
        scanf("%d", &value);
        root = insert(root, value);   
    }
    int testcase, v1, v2, ans;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d%d", &v1, &v2);
        if(search(root, v1)!= NULL && search(root, v2)!= NULL){
            ans = findLCA(root, v1, v2);
            printf("LCA of node (%d, %d): %d\n", v1, v2, ans);
        }
        else{
            printf("Node does not exist.\n");
        }
    }
}