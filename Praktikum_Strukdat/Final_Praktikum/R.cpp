#include <bits/stdc++.h>

int main(){
  int m, n;
  std::cin >> m >> n;
  std::vector <int> v1(m), v2(n);

  for(int i=0;i<m;i++)
    std::cin >> v1[i];
  for(int i=0;i<n;i++)
    std::cin >> v2[i];

  std::vector <int> v3;
  if(n < m) {
    v3.resize(m);
    int index = m-1;
    for(int i=n-1;i>=0;i--){
      int sum = v3[index] + v1[index] + v2[i];
      if(sum >= 10 && index != 0){
        int temp = sum/10;
        v3[index] = sum % 10;
        v3[index-1] += temp;
      }
      else
        v3[index] = sum;
      index--;
    }
    for(int i=index;i>=0;i--) {
      v3[i] += v1[i];
      if(v3[i] >= 10 && i != 0){
        int temp = v3[i]/10;
        v3[i] = v3[i] % 10;
        v3[i-1] += temp;
      }
    }
  } else {
    v3.resize(n);
    int index = n-1;
    for(int i=m-1;i>=0;i--){
      int sum = v3[index] + v1[i] + v2[index];
      if(sum >= 10 && index != 0){
        int temp = sum/10;
        v3[index] = sum % 10;
        v3[index-1] += temp;
      }
      else
        v3[index] = sum;
      index--;
    }
    for(int i=index;i>=0;i--) {
      v3[i] += v2[i];
      if(v3[i] >= 10 && i != 0){
        int temp = v3[i]/10;
        v3[i] = v3[i] % 10;
        v3[i-1] += temp;
      }
    }
  }
  for(int i=0;i<v3.size();i++)
    std::cout << v3[i];
}