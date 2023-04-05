#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bstnode{
    int data;
    struct bstnode *left, *right;
}node;

node* newNode(int value){
    node *temp = (node *)(malloc(sizeof(node)));
    temp->data = value;
    temp->left = temp->right = NULL;

    return temp;
}

node* insert(node *root, int value){
    if(root == NULL)
        root = newNode(value);
    else if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int findPathLength(node *root, int from, int to) {
    if (root == NULL)
        return -1;
    
    // If both nodes are in the left subtree
    if (from < root->data && to < root->data)
        return findPathLength(root->left, from, to);
    
    // If both nodes are in the right subtree
    else if (from > root->data && to > root->data)
        return findPathLength(root->right, from, to);

    // If the two nodes are on different subtrees, add up the path lengths
    else {
        int leftPath = findPathLength(root->left, from, root->data);
        int rightPath = findPathLength(root->right, to, root->data);
        return leftPath + rightPath + 2;
    }
}


int main(){
    node *root = NULL;

    int n, value;
    scanf("%d", &n);

    while(n--){
        scanf("%d", &value);
        root = insert(root, value);
    }
    int from, to;
    scanf("%d%d", &from, &to);

    printf("%d", findPathLength(root, from, to));
}
