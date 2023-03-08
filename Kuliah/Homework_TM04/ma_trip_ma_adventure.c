#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int l_path = 0, r_path = 0;

typedef struct bst_node{
    int data;
    int path_val;
    struct bst_node *left, *right;
}node;

node *newNode(int value, int path_val){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->path_val = path_val;
    temp->left = temp->right = NULL;

    return temp;
}

node *search(node *root, int value){
    if(root == NULL || value == root->data) return root;
    if(value < root->data) return search(root->left, value);
    else if(value > root->data) return search(root->right, value);
}

node *insert(node *root, int value, int path_val){
    if(root == NULL)
        root = newNode(value, path_val);
    else if(value < root->data)
        root->left = insert(root->left, value, path_val);
    else if(value > root->data)
        root->right = insert(root->right, value, path_val);

    return root;
}

int min(int a, int b){
    return ((a<b)? a : b);
}

bool isLeaf(node *root){
    if((root->left == NULL) && (root->right == NULL)) 
        return true;
    else
        return false;
}

int shortestLeaf(node *root){
    if(root == NULL) return 0;
    
    if(isLeaf(root)) return root->path_val;
    else{
        l_path += root->left->path_val;
        r_path += root->right->path_val;
        l_path += shortestLeaf(root->left);
        r_path += shortestLeaf(root->right);
    }
}

int main(){
    node *root = NULL;
    int N, r, path_val;
    scanf("%d%d", &N, &r);
    root = insert(root, r, 0);
    for(int i=1;i<N;i++){
        scanf("%d%d", &r, &path_val);
        root = insert(root, r, path_val);
    }
    int T, value;
    node *temp;
    scanf("%d", &T);
    while(T--){
        node *temp;
        scanf("%d", &value);
        temp = search(root, value);
        if(isLeaf(temp))
            printf("0\n");
        else{
            shortestLeaf(temp);
            printf("%d\n", min(l_path, r_path));
        }
    }

    return 0;
}