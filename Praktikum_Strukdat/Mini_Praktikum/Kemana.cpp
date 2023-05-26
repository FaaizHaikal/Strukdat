#include <bits/stdc++.h>

std::string s = "";
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

void search(Node *root, int value){
    if(root == NULL || value == root->data)
      s += "S";
    else if(value < root->data){
      s += "L";
      search(root->left, value);
    }
    else if(value > root->data){
      s += "R";
      search(root->right, value);
    }
}


int main(){
    Node *root = NULL;
    int n, value;
    std::cin >> n;
    while(n--){
      std::cin >> value;
      root = insert(root, value);
    }
    int m;
    std::cin >> m;
    while(m--){
      std::cin >> value;
      search(root, value);
      std::cout << s << "\n";
      s = "";
    }
    return 0;
}

