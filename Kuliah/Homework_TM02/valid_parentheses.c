#include <stdio.h>
#include <string.h>

#define SIZE 10001

int front_status(char str){
    if(str == '[' || str == '(' || str == '{')
        return 1; //opened parentheses
    else
        return 0; //closed parentheses
}

int back_status(char str){
    if(str == '[' || str == '(' || str == '{')
        return 1; //opened parentheses
    else
        return 0; //closed parentheses
}

int valid_check(char str_front, char str_back){
    if(str_front == '[' && str_back == ']')
        return 1;
    else if(str_front == '(' && str_back == ')')
        return 1;
    else if(str_front == '{' && str_back == '}')
        return 1;
    
    return 0;
}
int solve(char str[], int length){
    int front_end = (length/2) - 1;
    int back_end = front_end + 1;

    for(int i=front_end;i>=0;i--){
        if(front_status(str[front_end]) == 0 && back_status(str[back_end]) == 0 )
            return 0;
        else if(front_status(str[front_end]) == 1 && back_status(str[back_end]) == 1)
            return 0;
        else if(front_status(str[front_end]) == 1 && back_status(str[back_end]) == 0)
            if(valid_check(str[front_end], str[back_end]) == 0)
                return 0;
        else if(front_status(str[front_end]) == 0 && back_status(str[back_end]) == 1)
            if(valid_check(str[front_end-1], str[front_end]) == 0 || valid_check(str[back_end], str[back_end+1]) == 0)
                return 0;
    }

    return 1;

}

int main(){
    char str[SIZE];
    scanf("%s", str);
    int length = strlen(str);

    if(length%2!=0)
        printf("false");
    else{
        if(solve(str, length) == 1)
            printf("true");
        else
            printf("false");
    }

    return 0;
}