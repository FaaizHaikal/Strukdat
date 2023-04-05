#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node{
    int data;
    struct stack_node *next;
}Node;

Node *newNode(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    return temp;
}

Node *insert(Node *top, int value){
    if(top == NULL)
        top = newNode(value);
    else{
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->next = top;
        temp->data = value;
        top = temp;
    }

    return top;
}

Node *pop(Node *top){
    if(top == NULL){
        printf("Stack is empty.\n");
        return top;
    }
    else{
        Node *temp = top;
        temp = temp->next;

        printf("Popped: %d\n", top->data);
        free(top);

        return temp;
    }
}
void display(Node *top){
    if(top == NULL)
        printf("Stack is empty.\n");
    else{
        Node *temp = top;
        
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
        free(temp);
    }
}
int main(){
    Node *top = NULL;
    top = insert(top, 3);
    top = insert(top, 4);
    top = insert(top, 5);

    display(top);
    top = pop(top);
    display(top);
    top = pop(top);
    display(top);
    top = pop(top);
    display(top);
    top = pop(top);
    display(top);
    return 0;
}