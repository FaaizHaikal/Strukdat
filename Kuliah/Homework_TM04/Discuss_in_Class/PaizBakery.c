#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double sum = 0;
int count = 0;

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

int heightOfBST(node *root){
    if(root == NULL) return 0;
    else{
        int l_h = heightOfBST(root->left);
        int r_h = heightOfBST(root->right);

        return ((l_h >r_h) ? (l_h + 1) : (r_h+1));
    }
}
void getDataAtLevel(node *root, int level){
    if(root == NULL) return;
    else if(level == 0){
        count++;
        sum += root->data;
    }
    else if(level > 0){
        getDataAtLevel(root->left, level-1);
        getDataAtLevel(root->right, level-1);
    }
}
void average(node *root){
    int h = heightOfBST(root);
    double average;
    for(int i=0; i<h;i++){
        getDataAtLevel(root, i);
        average = sum/count;
        sum = 0;
        count = 0;
        printf("Level %d = %.2f\n", i, average);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    int price = 0;
    while(t--){
        node *root = NULL;
        scanf("%d", &price);
        while(price!=-1){
            root = insert(root, price);
            scanf("%d", &price);
        }
        average(root);
        free(root);
    }
}