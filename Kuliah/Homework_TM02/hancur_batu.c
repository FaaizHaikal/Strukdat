/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
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

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);

    int n;
    scanf("%d", &n);
    int batu, new_top, berat= 0;
    while(n--){
        scanf("%d", &batu);
        while(!stack_isEmpty(&myStack) && batu>=stack_top(&myStack)){
            stack_pop(&myStack);
            if(!stack_isEmpty(&myStack))
                new_top = (batu<stack_top(&myStack)) ? batu : stack_top(&myStack);
            else
                new_top = batu;
            berat += new_top;
        }
        stack_push(&myStack, batu);
    }

    while(myStack._size > 1){
        stack_pop(&myStack);
        berat += stack_top(&myStack);
    }

    printf("%d", berat);
    return 0;
}