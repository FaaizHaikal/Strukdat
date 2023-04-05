#include <bits/stdc++.h>

bool marker = false;

struct Node{
    int data;
    bool mostLeft, mostRight;
    struct Node *left, *right;
};

Node *newNode(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    temp->mostLeft = temp->mostRight = false;
    return temp;
}

Node *insert(Node *root, int value){
    if(root == NULL)
        root = newNode(value);
    else if(value < root->data){
        root->left = insert(root->left, value);
    }
        
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
        

    return root;
}

bool isLeaf(Node *root){
    return(root->left == NULL && root->right == NULL);
}

void checkSafe(Node *root){
    if(root == NULL || isLeaf(root))
        return;
    if(root->left != NULL && !isLeaf(root->left)){
        if(root->mostLeft)
            root->left->mostLeft = true;
        if(root->right == NULL)
            root->left->mostRight = true;
    }
    if(root->right != NULL && !isLeaf(root->right)){
        if(root->mostRight)
            root->right->mostRight = true;
        if(root->left == NULL)
            root->right->mostLeft = true;
    }

    checkSafe(root->left);
    checkSafe(root->right);

    
}

void inorder(Node *root){
    if(root == NULL || isLeaf(root))
        return;
    inorder(root->left);
    if(!root->mostLeft && !root->mostRight){
        std::cout << root->data << " ";
        marker = true;
    }
    inorder(root->right); 
}
int main(){
    Node *root = NULL;
    int n, value;
    std::cin >> n;
    std::cin >> value;
    root = insert(root, value);
    root->mostLeft = root->mostRight = true;

    n -= 1;
    for(int i=0;i<n;i++){
        std::cin >> value;
        root = insert(root, value);
    }
    checkSafe(root);

    inorder(root);
    if(!marker)
        std::cout << "It's not safe" << std::endl;

    return 0;
}

