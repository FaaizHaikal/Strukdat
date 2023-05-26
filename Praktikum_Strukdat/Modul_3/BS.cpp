#include <bits/stdc++.h>

bool isNotSafe = false;

struct Node{
    int data;
    Node *left, *right;
    int height;
};

int max(int a, int b){
    return (a > b) ? a : b;
}

int height(Node *node){
    if(node == NULL)
        return 0;
    return node->height;
}

int balanceFactor(Node *node){
    if(node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node *newNode(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->height = 1;
    temp->left = temp->right = NULL;

    return temp;
}

// Node *rightRotate(Node *pivotNode) {

//     Node *newParrent=pivotNode->left;
//     Node *temp = newParrent->right;
//     newParrent->right=pivotNode;
//     pivotNode->left = temp;

//     pivotNode->height=  1 + max(height(pivotNode->left), height(pivotNode->right));
//     newParrent->height=  1 + max(height(newParrent->left), height(newParrent->right));
    
//     return newParrent;
// }

// Node *leftRotate(Node *pivotNode){
//     Node *newParrent = pivotNode->right;
//     Node *temp = newParrent->left;
//     newParrent->left = pivotNode;
//     pivotNode->right = temp;

//     pivotNode->height=  1 + max(height(pivotNode->left), height(pivotNode->right));
//     newParrent->height=  1 + max(height(newParrent->left), height(newParrent->right));
    
//     return newParrent;

// }
Node *insert(Node *root, int value){
    if(root == NULL)
        return newNode(value);
    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    root->height = 1 + max(height(root->left), height(root->right));
    
    int balance = balanceFactor(root);

    if(balance>1 && value < root->left->data){
        isNotSafe = true;
    }

    if(balance>1 && value > root->left->data){
        isNotSafe = true;
    }
    if(balance < -1 && value > root->right->data){
        isNotSafe = true;
    }

    if(balance < -1 && value < root->right->data) {
        isNotSafe = true;
    }

    return root;
}

// Node *search(Node *root, int value){
//     if(root == NULL || value == root->data)
//         return root;
//     else if(value < root->data)
//         return search(root->left, value);
//     else if(value > root->data)
//         return search(root->right, value);
// }

// Node *parent(Node* root, int data) {
//     Node* parent = NULL;
//     Node* current = root;

//     while (current != NULL) {
//         if (data < current->data) {
//             parent = current;
//             current = current->left;
//         } else if (data > current->data) {
//             parent = current;
//             current = current->right;
//         } else {
//             return parent;
//         }
//     }
//     return NULL;
// }

void inorder(Node *root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    Node *root = NULL;
    char name[51];
    std::cin.getline(name, 51);

    int n, val;
    std::cin >> n;
    while(n--){
        std::cin >> val;
        if(isNotSafe)
            continue;
        root = insert(root, val);
    }
    if(isNotSafe)
        std::cout << name << " is suspicious, hang this person now!";
    else{
        std::cout << name << " is innocent.\n";
        inorder(root);
    }

}