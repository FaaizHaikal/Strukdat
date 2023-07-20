#include <bits/stdc++.h>

int main(){
  int n;
  std::cin >> n;
  while(n--){
    int t, x, max = 1;
    std::cin >> t;
    std::map<int, int> map;
    for(int i=0;i<t;i++){
      std::cin >> x;
      map[x]++;
    }
    for(auto i : map){
      i.second > max ? max = i.second : max = max;
    }

    int temp = t - max;
    int count = 0;
    max >= temp ? count = temp : count = t/2;
    int ans = t -(count * 2);
    std::cout << ans << "\n";
  }
}