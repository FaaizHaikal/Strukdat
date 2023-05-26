#include <bits/stdc++.h>

int bfs(std::vector<std::vector<int>> &maze, int a, int b, int n, int m){
    std::queue<std::pair<std::pair<int, int>, int>> q;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    q.push({{a, b}, 0});
    visited[a][b] = true;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int x = curr.first.first;
        int y = curr.first.second;
        int dist = curr.second;
        if(x == 0 || x == n-1 || y == 0 || y == m-1){
            return dist+1;
        }
        for(auto adj : std::vector<std::pair<int, int>>{{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}}){
            int x_adj = adj.first;
            int y_adj = adj.second;
            if(x_adj >= 0 && x_adj < n && y_adj >= 0 && y_adj < m && !visited[x_adj][y_adj] && maze[x_adj][y_adj] == 0){
                q.push({{x_adj, y_adj}, dist+1});
                visited[x_adj][y_adj] = true;
            }
        }
    }

    return 0;
}

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> maze(n, std::vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val;
            std::cin >> val;
            maze[i][j] = val;
        }
    }
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    std::cout << bfs(maze, a, b, n, m);
}