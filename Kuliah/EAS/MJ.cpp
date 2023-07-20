#include <bits/stdc++.h>

std::vector<int> par;
int find(int x) {
    if(par[x] != x) {
        return par[x] = find(par[x]);
    }
return x;
}

// total weight of mst
int kruskal(std::vector<std::vector<std::pair<int, int>>> &adjList, int n) {
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    for(int i=1;i<n;i++){
        for(auto adj : adjList[i]){
            int v = adj.first;
            int w = adj.second;
            edges.push_back({w, {i, v}});
        }
    }
    std::sort(edges.begin(), edges.end());
    int mst_weight = 0;
    for(auto edge : edges){
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        int par_u = find(u);
        int par_v = find(v);
        if(par_u != par_v){
            mst_weight += w;
            par[par_u] = par_v;
        }
    }
    return mst_weight;
}

int main() {
  int n, v, e;
  std::cin >> n >> v >> e;
  v++;
  std::vector<std::vector<std::pair<int, int>>> adjList(v);
  for(int i=0;i<e;i++){
    int a, b, w;
    std::cin >> a >> b >> w;
    adjList[a].push_back({b, w});
    adjList[b].push_back({a, w});
  }
  par.resize(v);
  for(int i=0;i<v;i++) par[i] = i;
  int old_x = kruskal(adjList, v);
  std::vector<int> dist(v, INT_MAX);
  for(int i=0;i<n;i++){
    int m, f, r;
    std::cin >> m >> f >> r;
    int A = 0;
    for(int j=0;j<m;j++){
      int a, b, w;
      std::cin >> a >> b >> w;
      A += w;
      adjList[a].push_back({b, w});
      adjList[b].push_back({a, w});
    }
    int B = 0;
    for(int j=0;j<f;j++){
      int a, b;
      std::cin >> a >> b;
      //find weight of a and b
      int w = 0;
      for(auto adj : adjList[a]) {
        int node = adj.first;
        if(node == b) {
          w = adj.second;
          break;
        }
      }
      B += w;
    }
    int C = 0;
    for(int j=0;j<r;j++){
      int a, b;
      std::cin >> a >> b;
      //remove edge between a and b from adjList
      int index = 0;
      int w = 0;
      for(auto adj : adjList[a]) {
        int node = adj.first;
        if(node == b) {
          w = adj.second;
          break;
        }
        index++;
      }
      C += w;
      adjList[a].erase(adjList[a].begin() + index);
      index = 0;
      for(auto adj : adjList[b]) {
        int node = adj.first;
        if(node == a) {
          break;
        }
        index++;
      }
      adjList[b].erase(adjList[b].begin() + index);
    }
    par.clear();
    par.resize(v);
    for(int j=0;j<v;j++) par[j] = j;
    int new_x = kruskal(adjList, v);

    int X = new_x - old_x;
    X *= 1000;
    A *= 5000;
    B *= 3000;
    C *= 2000;
    std::cout << X << " " << A << " " << B << " " << C << std::endl;
    std::cout << X+A+B+C << std::endl;
  }

}