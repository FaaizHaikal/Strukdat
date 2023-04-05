#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node{
	int data;
	int depth;
	struct bst_node *left, *right;
}Node;

int max(int a, int b){
	return (a > b) ? a : b;
}
Node *newNode(int value){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = value;
	temp->left = temp->right = NULL;
	temp->depth = 0;
	return temp;
}

int getDepth(Node *root){
	if(root == NULL)
		return 0;
	return root->depth;
}

Node *insert(Node *root, int value){
	if(root == NULL)
		root = newNode(value);
	else if(value < root->data){
		root->left = insert(root->left, value);
		root->depth = 1 + max(getDepth(root->left), getDepth(root->right));
	}
	else if(value > root->data){
		root->right = insert(root->right, value);
		root->depth = 1 + max(getDepth(root->left), getDepth(root->right));
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

int main(){
	Node *root = NULL;
	int n, value;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &value);
		root = insert(root, value);
	}
	scanf("%d", &value);
	Node *temp = search(root, value);
	int depth = getDepth(temp);

	printf("%d", depth*depth*10000);

}