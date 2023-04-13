#include <bits/stdc++.h>
std::map<std::string, std::vector<std::string>> Graph;
std::stack<std::string> lineage;

bool dfs(std::string A, std::string B){
    if(A==B)
        return true;
    for(auto i : Graph[A]){
        if(dfs(i, B)){
            lineage.push(i);
            return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    std::string A;
    std::string B;
    std::cin >> n >> m;
    while(m--){
        std::cin >> A >> B;
        Graph[A].push_back(B);
    }
    std::cin >> A >> B;

    if(dfs(A, B)){
        std::cout << A << "\n";
        while(!lineage.empty()){
            std::cout << lineage.top() << "\n";
            lineage.pop();
        }
    }
    else if(dfs(B, A)){
        std::cout << B << "\n";
        while(!lineage.empty()){
            std::cout << lineage.top() << "\n";
            lineage.pop();
        }
    }
    else
        std::cout << "TIDAK MUNGKIN\n";
}