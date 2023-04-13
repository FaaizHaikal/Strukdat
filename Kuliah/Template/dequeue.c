#include <stdio.h>
#include <stdlib.h>

typedef struct dequeue_node{
    int data;
    struct dequeue_node *next, *prev;
}Node;

typedef struct dequeue{
    Node *front, *rear;
    int size;
}Dequeue;

Dequeue *createDequeue(){
    Dequeue *dq = (Dequeue *)malloc(sizeof(Dequeue));
    dq->front = dq->rear = NULL;
    dq->size = 0;

    return dq;
}
Node *newNode(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    return temp;
}

void push_front(Dequeue *dq, int value){
    Node *temp = newNode(value);
    if(dq->front == NULL)
        dq->front = dq->rear = temp;
    else{
        temp->next = dq->front;
        dq->front->prev = temp;
        dq->front = temp;
    }
    
    dq->size++;
}

void push_back(Dequeue *dq, int value){
    Node *temp = newNode(value);
    if(dq->rear == NULL)
        dq->rear = dq->front = temp;
    else{
        dq->rear->next = temp;
        temp->prev = dq->rear;
        dq->rear = temp;
    }

    dq->size++;
}

void pop_front(Dequeue *dq){
    if(dq->front == NULL)
        printf("DEQUEUE IS EMPTY\n");
    else{
        Node *temp = dq->front;
        dq->front = dq->front->next;
        dq->front->prev = NULL;
        if(dq->front == NULL)
            dq->rear = NULL;
        free(temp);
    }

    dq->size--;
}

void pop_back(Dequeue *dq){
    if(dq->rear == NULL)
        printf("DEQUEUE IS EMPTY\n");
    else{
        Node *temp = dq->rear;
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
        if(dq->rear == NULL)
            dq->front = NULL;
        free(temp);
    }

    dq->size--;
}

void display(Dequeue *dq){
    if(dq->front == NULL)
        printf("DEQUEUE IS EMPTY\n");
    else{
        Node *temp = dq->front;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }   
        printf("\n");
    }
}
int main(){
    Dequeue *myDequeue;
    myDequeue = createDequeue();
    push_front(myDequeue, 3);
    push_front(myDequeue, 4);
    push_front(myDequeue, 5);
    
    display(myDequeue);
    printf("SIZE: %d\n", myDequeue->size);
    push_back(myDequeue, 6);
    push_back(myDequeue, 7);

    display(myDequeue);
    printf("SIZE: %d\n", myDequeue->size);
    pop_front(myDequeue);

    display(myDequeue);
    printf("SIZE: %d\n", myDequeue->size);
    pop_back(myDequeue);

    display(myDequeue);

    printf("SIZE: %d\n", myDequeue->size);
    return 0;
}