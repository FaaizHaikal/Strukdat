#include <bits/stdc++.h>

struct Node{
    int data;
    struct Node *left, *right;
};

bool flag = false;
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

bool isLeaf(Node *root){
    return(root->left == NULL && root->right == NULL);
}

void solve(Node *root, int k) {
  if(root == NULL || isLeaf(root) || flag)
    return;
  if(root->left != NULL && root->right != NULL){
    if(root->data + root->left->data + root->right->data == k){
      flag = true;
    }
  }
  if(root->left != NULL){
    if(root->left->left != NULL){
      if(root->data + root->left->data + root->left->left->data == k){
        flag = true;
      }
    }
    if(root->left->right != NULL){
      if(root->data + root->left->data + root->left->right->data == k){
        flag = true;
      }
    }
  }
  if(root->right != NULL){
    if(root->right->left != NULL){
      if(root->data + root->right->data + root->right->left->data == k){
        flag = true;
      }
    }
    if(root->right->right != NULL){
      if(root->data + root->right->data + root->right->right->data == k){
        flag = true;
      }
    }
  }
  solve(root->left, k);
  solve(root->right, k);
}

int main() {
  int n;
  std::cin >> n;
  Node *root = NULL;
  while(n--){
    int x;
    std::cin >> x;
    root = insert(root, x);
  }
  int k;
  std::cin >> k;
  solve(root, k);
  if(!flag)
    std::cout << k << " Tidak ada kombinasi yang tepat! Bikin ulang.";
  else
    std::cout << k << " Selamat! Kalian menemukan harta karunnya";
}