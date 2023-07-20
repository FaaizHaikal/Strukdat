#include <bits/stdc++.h>

void kruskal(std::vector<std::vector<std::pair<int, int>>> &adjList) {
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    for(int i=0;i<adjList.size();i++){
        for(auto j : adjList[i]){
            edges.push_back({j.second, {i, j.first}});
        }
    }
    std::sort(edges.begin(), edges.end());
    std::vector<std::pair<int, int>> mst;
    std::vector<int> parent(adjList.size());
    int ans = 0;
    for(int i=0;i<adjList.size();i++)
        parent[i] = i;
    for(auto i : edges){
        int u = i.second.first;
        int v = i.second.second;
        int w = i.first;
        int set_u = parent[u];
        int set_v = parent[v];
        if(set_u != set_v){
            mst.push_back({u, v});
            ans = std::max(ans, w);
            for(int j=0;j<adjList.size();j++){
                if(parent[j] == set_v)
                    parent[j] = set_u;
            }
        }
    }
    
    std::cout << ans;
}

int main(){
    int V, E;
    std::cin >> V >> E;
    V++;
    std::vector<std::vector<std::pair<int, int>>> adjList(V);
    while(E--){
        int x, y, w;
        std::cin >> x >> y >> w;
        adjList[x].push_back({y, w});
        adjList[y].push_back({x, w});
    }

    kruskal(adjList);
}