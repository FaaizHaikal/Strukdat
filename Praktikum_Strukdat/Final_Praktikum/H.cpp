#include <bits/stdc++.h>

struct Node{
  int data;
  struct Node *left, *right;
};
int level = 1;
int counter = 0;
std::string p = "";
Node *newNode(int value){
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = value;
  temp->left = temp->right = NULL;
  return temp;
}

bool isLeaf(Node *root){
  return(root->left == NULL && root->right == NULL);
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

Node *search(Node *root, int value){
  if(root == NULL || value == root->data)
    return root;
  else if(value < root->data) {
    level++;
    return search(root->left, value);
  }
  else if(value > root->data) {
    level++;
    return search(root->right, value);
  }
}

void path(Node *root, int value){
  if(root == NULL || value == root->data)
    p += 'S';
  else if(value < root->data) {
    p += 'L';
    path(root->left, value);
  }
  else if(value > root->data) {
    p += 'R';
    path(root->right, value);
  }
}

void inorder(Node *root, int val, int &ans){
  if(root == NULL)
      return;
  inorder(root->left, val, ans);
  counter++;
  if(counter == val) {
    ans = root->data;
    return;
  }
  inorder(root->right, val, ans); 
}

int main(){
  std::string cmd;
  Node *root = NULL;
  while(true){
    std::cin >> cmd;
    int val;
    level = 1;
    if (cmd[0] == 'I'){
      std::cin >> val;
      if(search(root, val) == NULL)
        root = insert(root, val);
    } else if (cmd[0] == 'F') {
      std::cin >> val;
      if(search(root, val) != NULL)
        std::cout << "on level " << level << "\n";
      else
        std::cout << "no " << val << "\n";
    } else if (cmd[0] == 'R') {
      std::cin >> val;
      int ans = -1;
      inorder(root, val, ans);
      if(ans == -1)
        std::cout << "-1\n";
      else
        std::cout << ans << "\n";
      counter = 0;
    } else if (cmd[0] == 'P') {
      std::cin >> val;
      if(search(root, val) != NULL) {
        path(root, val);
        std::cout << p << "\n";
        p = "";
      }
      else
        std::cout << "no " << val << "\n";
    } else {
      std::cout << "done\n";
      break;
    }
  }
}