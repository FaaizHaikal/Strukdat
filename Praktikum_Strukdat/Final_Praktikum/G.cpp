#include <bits/stdc++.h>
struct Node{
    int data;
    struct Node *left, *right;
};
bool marker = false;
Node *newNode(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->left = temp->right = NULL;
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

Node* findMinNode(Node *node) {
    Node *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

bool isLeaf(Node *root){
    return(root->left == NULL && root->right == NULL);
}

Node* remove(Node *root, int value) {
  if (root == NULL) return NULL;
    if (value > root->data) 
        root->right = remove(root->right, value);
    else if (value < root->data) 
        root->left = remove(root->left, value);
    else {
        if (root->left == NULL) {
            Node *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            Node *leftChild = root->left;
            free(root);
            return leftChild;
        }
        Node *temp = findMinNode(root->right);
        root->data     = temp->data;
        root->right   = remove(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root){
    if(root == NULL || isLeaf(root))
        return;
    inorder(root->left);
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)){
        marker = true;
        std::cout << root->data << " ";
    }
    inorder(root->right); 
}

int main(){
  int t;
  std::cin >> t;
  Node *root = NULL;
  std::string cmd;
  while(t--){
    std::cin >> cmd;
    if(cmd[0] == '1'){
      int val;
      std::cin >> val;
      root = insert(root, val);
  } else if(cmd[0] == '0') {
      int val;
      std::cin >> val;
      root = remove(root, val);
  } else {
    inorder(root);
    if(!marker)
      std::cout << "Use whatever means you must to control our population. Just do it.";
    std::cout << "\n";
  }
  }
}