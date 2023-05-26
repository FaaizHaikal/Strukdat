#include <bits/stdc++.h>

void dijkstra(std::vector<std::vector<std::pair<int, int>>> &adjList, int src, int target, std::vector<int> &dist){
    dist[src] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
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
    int V, E, a, b;
    std::cin >> V >> E;
    V++;
    std::vector<std::vector<std::pair<int, int>>> adjList(V);
    while(E--){
        int x, y;
        std::cin >> x >> y;
        adjList[x].push_back({y, 1});
        adjList[y].push_back({x, 1});
    }
    std::cin >> a >> b;
    std::vector<int> dist(V, INT_MAX);
    dijkstra(adjList, a, b, dist);
    std::cout << dist[b];
}