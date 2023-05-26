#include <bits/stdc++.h>
int smallest = 0;
std::vector<std::vector<int>> Graph;
void dfs(int start, std::vector<bool> &visited){
    visited[start] = true;
    for(int adj : Graph[start]){
        if(!visited[adj]){
            dfs(adj, visited);
        }
    }
}
int solve(int n){
    std::vector<bool> visited(n+1, false);
    int count = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i, visited);
            count++;
        }
    }
    return count;
}



int main(){
    
    int n, m;
    std::cin >> n >> m;
    Graph.resize(n+1);
    
    for(int i=0;i<m;i++){
        int a, b;
        std::cin >> a >> b;
        smallest = std::min(a, b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    std::cout << solve(n) - 1;

}