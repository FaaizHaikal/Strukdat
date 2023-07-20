#include <bits/stdc++.h>

void bfs(std::vector<std::vector<int>> &adjList, std::vector<int> &distance, int s) {
    distance[s] = 0;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto adj : adjList[v]) {
            if (distance[adj] == 0) {
                distance[adj] = distance[v] + 1;
                q.push(adj);
            }
        }
    }
}


int main(){
    int V;
    std::cin >> V;
    std::vector<std::vector<int>> adjList(V);
    while(true){
        int x, y;
        std::cin >> x >> y;
        if(x == -1 && y == -1) break;
        adjList[x].push_back(y);
    }
    for(int i=0;i<V;i++){
        std::vector<int> distance(V, 0);
        bfs(adjList, distance, i);
        if(distance[i] == 0) std::cout << "gak bisa pulang mamah" << "\n";
        else std::cout << distance[i] << "\n";
    }
}