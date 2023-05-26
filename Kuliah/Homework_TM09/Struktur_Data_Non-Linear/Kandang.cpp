#include <bits/stdc++.h>

std::vector<int> kandang;

int find(int x){
    if(kandang[x] == x){
        return x;
    }
    return kandang[x] = find(kandang[x]);
}

int main(){
    int n, q;
    std::cin >> n >> q;
    kandang.resize(n+1);
    for(int i = 1; i <= n; i++)
        kandang[i] = i;
    
    while(q--){
        int cmd, a, b;
        std::cin >> cmd >> a >> b;
        if(cmd == 1){
            a = find(a);
            b = find(b);
            if(a != b)
                kandang[b] = a;
            continue;
        }
        if(find(a) == find(b))
            std::cout << "Y\n";
        else
            std::cout << "T\n";
    }
}