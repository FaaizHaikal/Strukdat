#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node{
    int data;
    struct queue_node *next;
}Node;

typedef struct queue{
    struct queue_node *front, *rear;
    int size;
}Queue;

Queue *createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;

    return q;
}
Node *newNode(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    return temp;
}

void insert(Queue *q, int value){
    if(q->rear == NULL)
        q->front = q->rear = newNode(value);
    else{
        Node *temp = newNode(value);
        q->rear->next = temp;
        q->rear = temp;
    }

    q->size++;
}

void pop_front(Queue *q){
    if(q->front == NULL)
        printf("QUEUE IS EMPTY\n");
    else{
        Node *temp = q->front;
        q->front = q->front->next;
        if(q->front == NULL)
            q->rear == NULL;
        free(temp);
    }
}

void display(Queue *q){
    if(q->front == NULL)
        printf("QUEUE IS EMPTY\n");
    else{
        Node *temp = q->front;
        while (temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    Queue *myQueue;
    myQueue = createQueue();
    insert(myQueue, 2);
    insert(myQueue, 3);
    insert(myQueue, 4);
    display(myQueue);
    pop_front(myQueue);
    display(myQueue);
    pop_front(myQueue);
    display(myQueue);

}