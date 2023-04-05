#include <bits/stdc++.h>

struct Node{
    int data;
    Node *left, *right;
    int jarak;
};

Node *newNode(int value, int jarak){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->jarak = jarak;
    temp->left = temp->right = NULL;

    return temp;
}

Node *insert(Node *root, int value, int jarak){
    if(root == NULL)
        root = newNode(value, jarak);
    else if(value < root->data)
        root->left = insert(root->left, value, jarak);
    else if(value > root->data)
        root->right = insert(root->right, value, jarak);

    return root;
}

Node *search(Node *root, int value){
    if(root == NULL || value == root->data)
        return root;
    else if(value < root->data)
        return search(root->left, value);
    else if(value > root->data)
        return search(root->right, value);
}

bool isLeaf(Node *root){
    return (root->left == NULL && root->right == NULL);
}

int findPath(Node *root){
    if(isLeaf(root))
        return 0;
    else{
        
    }
}

int main(){
    Node *root = NULL;
    int k, value, jarak;
    std::cin >> k;
    std::cin >> value;

    root = insert(root, value, 0);
    for(int i=0;i<k-1;i++){
        std::cin >> value >> jarak;
        root = insert(root, value, jarak);
    }
    int t;
    std::cin >> t;
    while(t--){
        std::cin >> value;

    }
    
}