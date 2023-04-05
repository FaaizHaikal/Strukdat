#include <bits/stdc++.h>

struct node{
    int data;
    node *left, *right;
    int height;
};

int max(int a, int b){
    return (a > b) ? a : b;
}

int height(node *node){
    if(node == NULL)
        return 0;
    return node->height;
}

int balanceFactor(node *node){
    if(node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

node *newNode(int value){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->height = 1;
    temp->left = temp->right = NULL;

    return temp;
}

node *rightRotate(node *pivotNode) {

    node *newParrent=pivotNode->left;
    node *temp = newParrent->right;
    newParrent->right=pivotNode;
    pivotNode->left = temp;

    pivotNode->height=  1 + max(height(pivotNode->left), height(pivotNode->right));
    newParrent->height=  1 + max(height(newParrent->left), height(newParrent->right));
    
    return newParrent;
}

node *leftRotate(node *pivotNode){
    node *newParrent = pivotNode->right;
    node *temp = newParrent->left;
    newParrent->left = pivotNode;
    pivotNode->right = temp;

    pivotNode->height=  1 + max(height(pivotNode->left), height(pivotNode->right));
    newParrent->height=  1 + max(height(newParrent->left), height(newParrent->right));
    
    return newParrent;

}
node *insert(node *root, int value){
    if(root == NULL)
        return newNode(value);
    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    root->height = 1 + max(height(root->left), height(root->right));
    
    int balance = balanceFactor(root);

    if(balance>1 && value < root->left->data){
        return rightRotate(root);
    }

    if(balance>1 && value > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && value > root->right->data){
        return leftRotate(root);
    }

    if(balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// node *search(node *root, int value){
//     if(root == NULL || value == root->data)
//         return root;
//     else if(value < root->data)
//         return search(root->left, value);
//     else if(value > root->data)
//         return search(root->right, value);
// }

node *LCA(node *root, int asal, int tujuan){
    if(root == NULL)
        return root;
    else if(asal < root->data && tujuan < root->data)
        return LCA(root->left, asal, tujuan);
    else if(asal > root->data && tujuan > root->data)
        return LCA(root->right, asal, tujuan);
    else
        return root;
}

void findPath(node *root, int asal, int tujuan){
    node *lca = LCA(root, asal, tujuan);

    // std::cout << lca->data << std::endl;
    int jarak_asal = 0, jarak_tujuan = 0;

    struct node *temp = lca;
    while(temp->data != asal){
        if(asal < temp->data){
            jarak_asal += abs(temp->data - temp->left->data);
            temp = temp->left;
        }
        else{
            jarak_asal += abs(temp->data - temp->right->data);
            temp = temp->right;
        }
    }

    temp = lca;
    while(temp->data != tujuan){
        if(tujuan < temp->data){
            jarak_tujuan += abs(temp->data - temp->left->data);
            temp = temp->left;
        }
        else{
            jarak_tujuan += abs(temp->data - temp->right->data);
            temp = temp->right;
        }
    }


    std::cout << jarak_asal + jarak_tujuan << std::endl;
}
int main(){
    node *root = NULL;
    int n, value, asal, tujuan;
    std::cin >> n;
    while(n--){
        std::cin >> value;
        root = insert(root, value);
    }
    std::cin >> asal >> tujuan;
    findPath(root, asal, tujuan);
}