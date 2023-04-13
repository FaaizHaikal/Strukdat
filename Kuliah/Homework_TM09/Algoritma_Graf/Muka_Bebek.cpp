#include<bits/stdc++.h>

int prim(std::vector<std::vector<std::pair<int, int>>> &adjList, int n){
    std::vector<bool> visited(n, false);
    std::vector<int> dist(n, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    int count = 0;
    dist[0] = 0;
    pq.push({0, 0}); //src is always 0
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        count += dist[u];
        for(auto i : adjList[u]){
            int v = i.first;
            int weight = i.second;
            if(!visited[v] && dist[v] > weight){
                dist[v] = weight;
                pq.push({dist[v], v});
            }
        }
    }

    return count;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> adjList(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            std::cin >> a;
            if(j > i){
                adjList[i].push_back({j, a});
                adjList[j].push_back({i, a});
            }
        }
    }

    std::cout << prim(adjList, n);
}