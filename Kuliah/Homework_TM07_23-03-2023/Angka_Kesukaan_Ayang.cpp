#include <bits/stdc++.h>

int main(){
    int n, adj, value;
    std::vector<int> myvector;

    std::cin >> n >> adj;
    for(int i=0;i<n;i++){
        std::cin >> value;
        myvector.push_back(value);
    }

    std::sort(myvector.begin(), myvector.end());
    int count = 0;
    for(int i=0; i+adj <= n; i++){
        count += myvector[i+adj-1];
    }
    
    std::cout << count << std::endl;
}