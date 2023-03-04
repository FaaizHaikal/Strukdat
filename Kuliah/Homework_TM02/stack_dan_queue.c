#include <stdio.h>
#include <string.h>
#define SIZE 20001
int min = 1, max;
void push_back(int ar[], int *backp){
    int value;
    scanf("%d", &value);
    ar[*backp] = value;
    min = (value < min) ? value : min;
    *backp += 1;
}
void push_front(int ar[], int *frontp){
    int value;
    scanf("%d", &ar[*frontp]);
    ar[*frontp] = value;
    *frontp -= 1;
}
void pop_front(int *frontp, int *backp){
    if(*backp == *frontp){
        return;
    }
    else
        *frontp += 1;
}
void pop_back(int *backp, int *frontp){
    if(*backp == *frontp){
        return;
    }
    else
        *backp -= 1;
}   

int main(){
    int ar[SIZE];
    int n, value;

    //init
    int front = SIZE/2;
    int back = front+1;

    char command[11];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", command);
        if(strcmp(command, "push")==0)
            push_back(ar, &back);
        else if(strcmp(command, "push_front")==0)
            push_front(ar, &front);
        else if(strcmp(command, "pop_front")==0)
            pop_front(&front, &back);
        else
            pop_back(&back, &front);
    }
    for(int i=front+1; i<back;i++)
        printf("%d\n", ar[i]);
    return 0;
}
