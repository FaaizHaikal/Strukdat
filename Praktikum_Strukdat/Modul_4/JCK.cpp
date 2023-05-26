#include <bits/stdc++.h>

int bfs(std::vector<std::vector<int>> &Graph, int start, int r, int n){
    std::vector<bool> visited(n, false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;
    std::vector<int> distance(n, 0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(distance[u] >= r)
            continue;
        for(int i=0;i<Graph[u].size();i++){
            int v = Graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                count++;
                distance[v]++;
                distance[v]+= distance[u];
            }
        }
    }
    return count;
}

int main(){
    std::vector<std::vector<int>> Graph;
    int n, m, start;
    std::cin >> n >> m >> start;
    Graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a, b;
        std::cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    int t;
    std::cin >> t;
    while(t--){
        int r;
        std::cin >> r;
        std::cout << bfs(Graph, start, r, n+1) << "\n";
    }
}