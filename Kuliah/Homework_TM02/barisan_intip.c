#include <stdio.h>
#define ll long long


int main(){
    struct bebek{
        ll tinggi;
        ll intip;
    };

    struct bebek bebek[100005];
    int n;
    ll count = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld", &bebek[i].tinggi);
        bebek[i].intip = 1;
        int j = i-1;
        while(j>0){
            if(bebek[i].tinggi >= bebek[j].tinggi){
                bebek[i].intip += bebek[j].intip;
                j -= bebek[j].intip;
            }
            else
                break;
        }
        count += bebek[i].intip;
    }
    printf("%lld\n", count);

}