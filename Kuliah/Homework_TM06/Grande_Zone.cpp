#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    scanf("%d", &n);
    std::vector<int> vec(n);
    for(int i=0;i<n;i++){
        std::cin >> vec[i];
    }
    int max = 0;
    int adj = 1;
    while (adj <= n) {
        for (int i=0; i<=(n-adj); i++) {
            int min = *min_element(vec.begin()+i, vec.begin()+i+adj);
            int value = adj * min;
            if (value > max){
                max = value;
            }
        }
        adj++;
    }

    std::cout << max << std::endl;
}