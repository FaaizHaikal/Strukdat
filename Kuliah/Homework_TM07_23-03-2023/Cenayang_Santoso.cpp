#include <bits/stdc++.h>

bool safe = false;

struct Node{
    int data;
    struct Node *left, *right;
};


std::vector<int> mostSide;

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

void findMostSide(Node *root){
    if(root == NULL)
        return;
    std::vector<std::vector<int>> levels;
    std::queue<Node*> myq;
    myq.push(root);

    while (!myq.empty()) {
        int size = myq.size();
        std::vector<int> temp;

        for (int i = 0; i < size; i++) {
            Node* current = myq.front();
            myq.pop();
            temp.push_back(current->data);

            if (current->left != NULL) {
                myq.push(current->left);
            }
            if (current->right != NULL) {
                myq.push(current->right);
            }
        }
        levels.push_back(temp);
    }
    mostSide.push_back(levels[0][0]);
    for(int i =1; i<levels.size(); i++){
        int j = levels[i].size();
        mostSide.push_back(levels[i][0]);
        mostSide.push_back(levels[i][j-1]);
    }
}

void inorder(Node *root){
    if(root == NULL || isLeaf(root))
        return;
    inorder(root->left);
    bool found = false;
    for(int i=0;i<mostSide.size();i++){
        if(root->data == mostSide[i]){
            mostSide.erase(mostSide.begin()+i);
            found = true;
            break;
        }
    }
    if(!found){
        safe = true;
        std::cout << root->data << " ";
    }
        
    inorder(root->right); 
}
int main(){
    Node *root = NULL;
    int n, value;
    std::cin >> n;
    if(n > 6){
        for(int i=0;i<n;i++){
            std::cin >> value;
            root = insert(root, value);
        }
        findMostSide(root);
        inorder(root);
        if(!safe)
            std::cout << "Yah, gk ada posisi yang aman :(";
    }
    else{
        for(int i=0;i<n;i++)
            std::cin >> value;
        std::cout << "Yah, gk ada posisi yang aman :(";
    }
    return 0;
}

