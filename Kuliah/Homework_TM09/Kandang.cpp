#include <bits/stdc++.h>

bool dfs(std::vector<std::vector<int>>& Graph, int asal, int tujuan, std::vector<bool>& mark) {
    if (Graph[asal][tujuan] == 1) {
        return true;
    }
    mark[asal] = true;
    for (int i = 0; i < Graph.size(); i++) {
        if (Graph[asal][i] == 1 && !mark[i]) {
            if (dfs(Graph, i, tujuan, mark)) {
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    n++;
    std::vector<std::vector<int>> Graph(n, std::vector<int>(n, 0));
    for(int i=1;i<n;i++)
        Graph[i][i] = 1;
    int t, a, b;
    while(q--){
        scanf("%d%d%d", &t, &a, &b);
        if(t == 1){
            Graph[a][b] = 1;
            Graph[b][a] = 1;
            continue;
        } else if(t == 2) {
            std::vector<bool> mark(n, false);
            if (dfs(Graph, a, b, mark)) {
                printf("Y\n");
            } else {
                printf("T\n");
            }
        }
    }

    return 0;
}
