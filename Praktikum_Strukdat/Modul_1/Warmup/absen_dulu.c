#include <stdio.h>

int main(){
    int n, value, hadir=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &value);
        switch (value)
        {
        case 1:
            hadir++;
            break;
        default:
            break;
        }
    }
    printf("%d %d", hadir, n-hadir);

    return 0;
}