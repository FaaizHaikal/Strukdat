#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, adj, value;
    std::vector<int> myvector;

    std::cin >> n >> adj;
    while(n--){
        std::cin >> value;
        myvector.push_back(value);
    }

    std::sort(myvector.begin(), myvector.end());
    int count = 0;
    for(int i=0; i+adj <= n; i++)
        count += *std::max_element(myvector.begin()+i, myvector.begin()+i+adj);

    std::cout << count << std::endl;
}