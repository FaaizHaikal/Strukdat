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

void getSumAtLevel(node *root, int level){
    if(root == NULL) return;
    else if(level == 0) sum += root->data;
    else if(level > 0){
        getSumAtLevel(root->left, level-1);
        getSumAtLevel(root->right, level-1);
    }
}

void printSumAtLevel(node *root, int level){
    getSumAtLevel(root, level);
    if(sum == 0) printf("GG EZ\n");
    else printf("Level %d: %d\n", level, sum);
    sum = 0;
}

int main(){
    node *root = NULL;
    int query;
    scanf("%d", &query);
    int id_q, input_query;
    while(query--){
        scanf("%d%d", &id_q, &input_query);
        switch (id_q)
        {
        case 1:
            root = insert(root, input_query);
            break;
        case 2:
            printSumAtLevel(root, input_query);
            break;
        default:
            break;
        }
    }

    return 0;
}