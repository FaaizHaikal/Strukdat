#include <bits/stdc++.h>

int main(){
    std::priority_queue<int> pq;
    int n, t;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &t);
        switch(t){
            case 1:
                int x;
                scanf("%d", &x);
                pq.push(x);
                break;
            case 2:
                printf("%d\n", pq.top());
                break;
            default:
                pq.pop();
                break;
        }
    }
}