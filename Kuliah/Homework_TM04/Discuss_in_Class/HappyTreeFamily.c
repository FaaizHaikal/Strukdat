#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct bst_node{
    int data;
    struct bst_node *left, *right;
};

struct bst_node *newNode(int value){
    struct bst_node *temp = (struct bst_node *)malloc(sizeof(struct bst_node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct bst_node *insert(struct bst_node *node, int value){
    if(node == NULL)
        node = newNode(value);
    else if(value < node->data)
        node->left = insert(node->left, value);
    else if(value > node->data)
        node->right = insert(node->right, value);

    return node;
}

struct bst_node *findParent(struct bst_node *root, struct bst_node *node) {
    if (root == NULL || node == root) {
        return NULL;
    }
    
    struct bst_node *current = root;
    struct bst_node *parent = NULL;
    
    while (current != NULL) {
        if (node->data < current->data) {
            parent = current;
            current = current->left;
        } else if (node->data > current->data) {
            parent = current;
            current = current->right;
        } else {
            return parent;
        }
    }
    return NULL;
}
struct bst_node *search(struct bst_node *node, int value){
    if(node == NULL || value == node->data) return node;
    if(value < node->data) return search(node->left, value);
    else if(value > node->data) return search(node->right, value);
}

int main(){
    struct bst_node *root = NULL;
    int n;
    scanf("%d", &n);
    int value;
    while(n--){
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\n");
    int m;
    scanf("%d", &m);
    int key;
    struct bst_node *node;
    struct bst_node *parent;
    while(m--){
        scanf("%d", &key);
        node = search(root, key);
        if(node != NULL){
            parent = findParent(root, node);
            if(parent != NULL) printf("%d ", parent->data);
            else printf("-1 ");
            if(node->left != NULL) printf("%d ", node->left->data);
            if(node->right != NULL) printf("%d", node->right->data);
            printf("\n");
        }
        else{
            printf("404 Not Found\n");
        }
    }
}