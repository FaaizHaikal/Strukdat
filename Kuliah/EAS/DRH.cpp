#include <bits/stdc++.h>

int main() {
  int n, u;
  std::cin >> n >> u;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  int temp = n - u;
  for(int i = u-1; i >= 0; i--){
    std::cout << v[i] << " ";
  }
  for(int i=u; i < n; i++){
    std::cout << v[i] << " ";
  }
}