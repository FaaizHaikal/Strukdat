#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int ar[n];
    for(int i=0;i<n;i++)
        scanf("%d", &ar[i]);
    int bit[2] = {0, 2147483647};
    int q, id, num;
    char command[4];
    scanf("%d", &q);
    while(q--){
        scanf("%d", &id);
        switch (id)
        {
        case 1:
            scanf("%s %d", command, &num);
            for(int i=0;i<2;i++){
                if(command[0] == 'A') bit[i] &= num; 
                else if(command[0] == 'O') bit[i] |= num;
                else bit[i] ^= num;
            }
            break;
        default:
            for(int i=0;i<n;i++){
                int temp = ar[i];
                int real =0;
                for(int j=0;j<30;j++){
                    int right = temp & 1;
                    int mybit = (bit[right] >> j) &1;
                    real |= (mybit << j);

                    temp >>= 1;
                }
                printf("%d%c", real, (i == n - 1 ? '\n' : ' '));
            }
            break;
        }
    }

}