#include <bits/stdc++.h>

struct Node{
    int data;
    int depth;
    struct Node *left, *right;
};

std::vector<int> currDepth;
int maxdepth = -1;
Node *newNode(int value, int depth){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    temp->depth = depth;
    return temp;
}

void findLevel(Node *root, int depth){
    if(root != NULL){
        findLevel(root->left, depth);
        if(root->depth == depth){
            currDepth.push_back(root->data);
        }
        findLevel(root->right, depth);
    }
}

Node *insert(Node *root, int value, int depth){
    if(root == NULL){
        root = newNode(value, depth);
        maxdepth = (depth > maxdepth) ? depth : maxdepth;
    }
    else if(value < root->data){
        root->left = insert(root->left, value, depth+1);
    }
    else if(value > root->data){
        root->right = insert(root->right, value, depth+1);
    }

    return root;
}

Node *search(Node  *root, int value){
    if(root == NULL || root->data == value)
        return root;
    else if(value < root->data)
        return search(root->left, value);
    else if(value > root->data)
        return search(root->right, value);
}

bool isLeaf(Node *root){
    return (root->left == NULL && root->right == NULL);
}
int main(){
    Node *root = NULL;
    std::vector<std::vector<int>> depths;
    int n, value;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &value);
        root = insert(root, value, 0);
    }
    maxdepth--;

    for(int i=maxdepth;i>1;i--){
        findLevel(root, i);
        depths.push_back(currDepth);
        currDepth.clear();
    }
    maxdepth--;
    for(int i=0;i<maxdepth;i++){
        if(depths[i].size() > 1){
            depths[i].erase(depths[i].begin());
            depths[i].erase(depths[i].end() - 1);
        }
        else if(depths[i].size() == 1)
            depths[i].erase(depths[i].begin());
    }
    for(int i=0;i<maxdepth;i++){
        currDepth.insert(currDepth.end(), depths[i].begin(), depths[i].end());
    }

    if(currDepth.size() > 0){
        std::sort(currDepth.begin(), currDepth.end());
        bool exist = false;
        for(int i=0;i<currDepth.size();i++){
            Node *temp = search(root, currDepth[i]);
            if(temp == NULL || isLeaf(temp))
                continue;
            exist = true;
            std::cout << temp->data << " ";
        }
        if(!exist){
            std::cout << "Strategi Syulit";
        }
    }
    else{
        std::cout << "Strategi Syulit";
    }
    return 0;
}