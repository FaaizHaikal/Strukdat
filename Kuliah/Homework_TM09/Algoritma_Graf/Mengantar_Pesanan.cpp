#include <bits/stdc++.h>

void dijkstra(std::vector<std::vector<std::pair<int, int>>> &adjList, int src, int target, std::vector<int> &dist){
    dist[src] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(u == target) break;
        for(auto i : adjList[u]){
            int v = i.first;
            int weight = i.second;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    int n, m, q;
    std::cin >> n >> m >> q;
    n++;
    std::vector<std::vector<std::pair<int, int>>> adjList(n);
    while(m--){
        int a, b, w;
        std::cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }
    int dest[q];
    for(int i=0;i<q;i++){
        std::cin >> dest[i];
    }
    int count = 0;
    for(int i=0;i<q-1;i++){
        std::vector<int> dist(n, INT_MAX);
        dijkstra(adjList, dest[i], dest[i+1], dist);
        count += dist[dest[i+1]];
    }

    std::cout << count;
}