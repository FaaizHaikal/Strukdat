#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    std::map<std::string, int> m;
    while(n--){
        std::string name;
        std::cin >> name;
        m[name]++;
    }

    for(auto it = m.begin(); it != m.end(); it++){
        std::cout << it->first << ": " << it->second << "\n";
    }
}