#include <iostream>
#include <vector>
#include <string>

using namespace std;

void find_rectangles(const vector<vector<int>>& matrix);

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            matrix[i][j] = stoi(string(1, s[j]));
        }
    }

    find_rectangles(matrix);

    return 0;
}

void find_rectangles(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int r1 = 0; r1 < n; r1++) {
        for (int c1 = 0; c1 < m; c1++) {
            if (matrix[r1][c1] == 0) {
                int r2 = r1, c2 = c1;
                while (r2 < n && matrix[r2][c1] == 0) r2++;
                while (c2 < m && matrix[r1][c2] == 0) c2++;

                if ((r2 - r1) * (c2 - c1) >= 10) {
                    cout << "Rectangle found at (" << r1 << "," << c1 << "), (" << r2-1 << "," << c2-1 << ")" << endl;
                }
            }
        }
    }
}
