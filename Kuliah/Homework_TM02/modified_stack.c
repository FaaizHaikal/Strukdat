#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
    int count;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;


void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}


void add(Stack *stack) 
{
    int x, y;
    scanf("%d%d", &x, &y);
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size+=y;
        newNode->data = x;
        newNode->count += y;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void del(Stack *stack, int x) 
{
    if (!stack_isEmpty(stack)){
        StackNode *temp = stack->_top;
        if(temp->count > 1){
            temp->count--;
            stack->_size--;
            return;
        }
        stack->_top = stack->_top->next;
        stack->_size--;
    }
}

void adx(Stack *stack, int x){
    StackNode *temp = stack->_top;
    while(temp != NULL){
        temp->data+=x;
        temp = temp->next;
    }
}

void dex(Stack *stack, int x){
    StackNode *temp = stack->_top;
    while(temp != NULL){
        temp->data-=x;
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    Stack myStack;

    stack_init(&myStack);

    int n;
    scanf("%d", &n);
    char command[4];
    while(n--){
        scanf("%s", command);
        if(strcmp(command, "add") == 0){
            add(&myStack);
            printf("%d\n", stack_size(&myStack));
        }
            
        else{
            int x;
            scanf("%d", &x);
            if(strcmp(command, "del") == 0){
                printf("%d\n", stack_top(&myStack));
                for(int i=0;i<x;i++)
                    del(&myStack, x);
            }
                
            else if(strcmp(command, "adx") == 0)
                adx(&myStack, x);
            else
                dex(&myStack, x);
        }
    }
    return 0;
}