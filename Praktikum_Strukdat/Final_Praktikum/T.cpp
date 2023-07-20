#include <bits/stdc++.h>

std::vector<int> bfs(const std::vector<std::vector<int>>& adjList, int start, int target) {
    std::vector<bool> visited(adjList.size(), false);
    std::vector<int> parent(adjList.size(), -1);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == target) {
            std::vector<int> path;
            int node = current;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            return path;
        }

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }

    return std::vector<int>();
}

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> adjList(V+1);
    for (int i = 0; i < E; ++i) {
        int u, v;
        std::cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    std::vector<int> path = bfs(adjList, 1, V);

    if (!path.empty()) {
        std::cout << path.size() << "\n";
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            std::cout << *it;
            if (it + 1 != path.rend())
                std::cout << " ";
        }
    } else {
        std::cout << "RIP LAPET 2023";
    }

    return 0;
}
