#include <bits/stdc++.h>

void bellmand_ford(std::vector<std::vector<std::pair<int, int>>> &Graph, int V){
    std::vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    for(int i=0;i<V-1;i++){
        for(int j=0;j<V;j++){
            for(auto k : Graph[j]){
                int v = k.first;
                int w = k.second;
                if(dist[j] + w < dist[v] && dist[j] != INT_MAX)
                    dist[v] = dist[j] + w;
            }
        }
    }
    for(int i=0;i<V;i++){
        for(auto j : Graph[i]){
            int v = j.first;
            int w = j.second;
            if(dist[i] + w < dist[v] && dist[i] != INT_MAX){
                std::cout << "Pak Dengklek tidak mau pulang\n";
                return;
            }
        }
    }
    if(dist[V-1] == INT_MAX)
        std::cout << "Tidak ada jalan\n";
    else
        std::cout << dist[V-1] << '\n';
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        int v, e;
        std::cin >> v >> e;
        std::vector<std::vector<std::pair<int, int>>> Graph(v);
        for(int i=0;i<e;i++){
            int a, b, w;
            std::cin >> a >> b >> w;
            Graph[a].push_back({b, w});
        }
        
        bellmand_ford(Graph, v);
    }
}