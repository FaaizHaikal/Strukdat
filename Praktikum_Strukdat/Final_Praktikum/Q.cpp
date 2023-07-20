#include <bits/stdc++.h>
int curr_price = INT_MAX;
int best_place;
std::map<int, std::pair<std::string, int>> places;
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
void bfs(std::vector<std::vector<std::pair<int, int>>> &adj, int max_dist){
  int size = adj.size();
  std::vector<bool> visited(size, false);
  std::queue<std::pair<int,int>> q;
  q.push({0, 0});
  while(!q.empty()){
    int node = q.front().first;
    int dist = q.front().second;
    q.pop();
    if(dist < max_dist && node != 0) {
      if(places[node].second < curr_price){
        curr_price = places[node].second;
        best_place = node;
      }
    }

    visited[node] = true;
    for (auto neighbor : adj[node]) {
      int neighbor_node = neighbor.first;
      int neighbor_dist = neighbor.second;
      if (!visited[neighbor_node]) {
          q.push({neighbor_node, dist + neighbor_dist});
      }
    }
  }
}

int main(){
  int V;
  std::cin >> V;
  std::vector<std::vector<std::pair<int, int>>> adj(V+1);
  
  for(int i=0;i<V;i++){
    std::string place_name;
    int price;
    std::cin >> place_name >> price;
    places[i+1] = {place_name, price};
  }
  int E;
  std::cin >> E;
  for(int i=0;i<E;i++){
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  int max_dist;
  std::cin >> max_dist;
  kruskal(adj);
  bfs(adj, max_dist);
  std::cout << "hari ini makan di " << places[best_place].first;
}