

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct pqueueNode_t {
    int data;
    struct pqueueNode_t *next;
} PQueueNode;


typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;


void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

int main(int argc, char const *argv[])
{

    PriorityQueue myPque;

    pqueue_init(&myPque);

    int d1, d2, c;
    scanf("%d%d", &d1, &d2);
    while(d1--){
        scanf("%d", &c);
        pqueue_push(&myPque, c);
    }
    while(d2--){
        scanf("%d", &c);
        pqueue_push(&myPque, c);
    }

    while (!pqueue_isEmpty(&myPque)) {
        printf("%d ", pqueue_top(&myPque));
        pqueue_pop(&myPque);
    }
    return 0;
}
