#include <bits/stdc++.h>

void bfs(std::vector<std::vector<std::pair<int, int>>> &adjList, int n, int src) {
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int curr_node = q.front();
        visited[curr_node] = true;
        std::cout << curr_node << std::endl;
        q.pop();
        for(auto adj : adjList[curr_node]){
            int v = adj.first;
            if(!visited[v])
                q.push(v);
        }
    }
}

void dfs(int start, std::vector<bool> &visited, std::vector<std::vector<std::pair<int, int>>> &adjList){
    std::cout << start << std::endl;
    visited[start] = true;
    for(auto adj : adjList[start]){
        int v = adj.first;
        if(!visited[v]){
            dfs(v, visited, adjList);
        }
    }
}

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
            for(int j=0;j<adjList.size();j++){
                if(parent[j] == set_v)
                    parent[j] = set_u;
            }
        }
    }
}

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

    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> visited(V, false);
    dfs(1, visited, adjList);
}