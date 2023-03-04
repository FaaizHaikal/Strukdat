#include <stdio.h>
#include <string.h>

#define MAX 10000000
int count = 0;
int front = MAX/2;
int rear = (MAX/2)+1;
int rev = 0;

void add(int ar[]){
    int x, y;
    scanf("%d%d", &x, &y);
    if((rev%2)==0){
        for(int i=0;i<y;i++){
            ar[rear] = x;
            rear++;
        }
    }
       
    else{
        for(int i=0;i<y;i++){
            ar[front] = x;
            front--;
        }
    }
    count += y;
    if(count < 0)
        count = 0;
    printf("%d\n", count);
}

void del(int ar[]){
    int y;
    scanf("%d", &y);
    if((rev%2)==0){
        printf("%d\n", ar[front+1]);
        front += y;
    }
    else{
        printf("%d\n", ar[rear-1]);
        rear -= y;
    }
    count -= y;
}

int main(){
    int ar[MAX];
    char command[4];
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", command);
        if(strcmp(command, "add")==0)
            add(ar);
        else if(strcmp(command, "del")==0)
            del(ar);
        else if(strcmp(command, "rev")==0)
            rev+=1;
    }
    return 0;
}