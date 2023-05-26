#include <bits/stdc++.h>

bool safe(int x, int y, int N, int M) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

void solve(std::vector<std::vector<int>>& ar, std::vector<std::vector<bool>>& visited, int x, int y, int& luas) {
    visited[x][y] = true;
    luas++;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (safe(nx, ny, ar.size(), ar[0].size()) && ar[nx][ny] == 1 && !visited[nx][ny]) {
            solve(ar, visited, nx, ny, luas);
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> ar(N, std::vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> ar[i][j];
        }
    }

    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));

    int island = 0;
    int area = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ar[i][j] == 1 && !visited[i][j]) {
                int luas = 0;
                solve(ar, visited, i, j, luas);

                island++;
                if(luas > area)
                  area = luas;
            }
        }
    }

    std::cout << "Banyak Pulau: " << island << std::endl;
    std::cout << "Luas Terbesar: " << area << std::endl;

    return 0;
}