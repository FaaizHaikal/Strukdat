#include <bits/stdc++.h>

std::vector<std::vector<int>> Graph(505);
int bfs(int awal, int tujuan){
    std::queue <int> q;
    q.push(awal);
    std::vector<int> jalan(505, -1);
    jalan[awal] = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto i : Graph[temp]){
            if(jalan[i] == -1){
                jalan[i] = jalan[temp]+1;
                q.push(i);
            }
        }
    }
    return jalan[tujuan];
}

int main(){
    int n, l, t, awal, tujuan;
    std::cin >> n >> l >> t >> awal >> tujuan;
    
    int a, b;
    while(l--){
        std::cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    int ans = 1e9;
    while(t--){
        std::cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        int temp = bfs(awal, tujuan);
        if(temp != -1 && temp < ans)
            ans = temp;
        Graph[a].pop_back();
        Graph[b].pop_back();
    }

    std::cout << ans;
    return 0;
}