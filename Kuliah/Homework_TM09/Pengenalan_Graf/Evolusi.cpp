#include <bits/stdc++.h>
std::map<std::string, std::vector<std::string>> Graph;  /* Graph hubungan keturunan tiap spesies */
std::stack<std::string> lineage;                        /* Urutan spesies dari yang paling tua */

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
    int n;              /* Banyaknya spesies (node) */
    int m;              /* Banyaknya hubungan keturunan spesies (edges) */
    std::string A;      /* Spesies anscestor */
    std::string B;      /* Spesies descendant */

    /* Masukkan data int N dan int M */
    std::cin >> n >> m;

    /* Masukkan data spesies */
    while(m--){
        std::cin >> A >> B;
        Graph[A].push_back(B);
    }

    /* Masukkan spesies yang ingin dicari keturnannya */
    std::cin >> A >> B;

    /* Cari keturunan spesies */
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