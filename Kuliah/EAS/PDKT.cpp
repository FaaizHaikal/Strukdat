#include <bits/stdc++.h>
std::map<std::string, int> priceList;
std::map<std::string, int> nodeMap;
std::map<int, std::string> stringMap;
// function to convert graph into minimum spanning tree
void prim(std::vector<std::vector<std::pair<int, int>>> &adjList, int n, std::vector<int> &dist, std::vector<int> &totalPrice){
    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        for(auto i : adjList[u]){
            int v = i.first;
            int weight = i.second;
            std::string s1 = stringMap[v];
            if (priceList[s1] + totalPrice[u] < totalPrice[v]) {
              totalPrice[v] = priceList[s1] + totalPrice[u];
            }
            if(!visited[v] && weight + dist[u] < dist[v]){
              dist[v] = weight + dist[u];
              pq.push({dist[v], v});
            }
        }
    }
}
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

int main(){
  int n, m;
  std::cin >> n >> m;
  n++;
  priceList["kaela"] = 0;
  nodeMap["kaela"] = 0;
  stringMap[0] = "kaela";
  for(int i=1;i<n;i++){
    std::string s;
    int price;
    std::cin >> s >> price;
    priceList[s] = price;
  }
  std::vector<std::vector<std::pair<int, int>>> adjList(n);
  int j = 1;
  for(int i=0;i<m;i++){
    std::string s1, s2;
    int weight;
    std::cin >> s1 >> s2 >> weight;
    if(nodeMap[s1] == 0 && s1 != "kaela") {
      nodeMap[s1] = j;
      stringMap[j] = s1;
      j++;
    }
    if(nodeMap[s2] == 0 && s2 != "kaela") {
      nodeMap[s2] = j;
      stringMap[j] = s2;
      j++;
    }
    adjList[nodeMap[s1]].push_back({nodeMap[s2], weight});
    adjList[nodeMap[s2]].push_back({nodeMap[s1], weight});
  }
  int q;
  std::vector<int> dist(n, INT_MAX);
  std::vector<int> totalPrice(n, INT_MAX);
  prim(adjList, n, dist, totalPrice);
  std::cin >> q;
  while(q--) {
    int num;
    std::string name;
    std::cin >> num >> name;
    if(dist[nodeMap[name]] == INT_MAX || totalPrice[nodeMap[name]] == INT_MAX) {
      std::cout << "-1" << std::endl;
      continue;
    }
    switch(num){
      case 2:
        std::cout << dist[nodeMap[name]] << std::endl;
        break;
      case 1:
        std::cout << totalPrice[nodeMap[name]] << std::endl;
    }
  }
}