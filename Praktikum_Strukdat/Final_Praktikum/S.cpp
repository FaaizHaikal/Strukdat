#include <bits/stdc++.h>

int main(){
  int n, k;
  std::cin >> n >> k;
  std::vector<int> arr(n);
  for(int i=0;i<n;i++)
    std::cin >> arr[i];
  
  std::vector<int> res;

  int count = 0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      int temp = std::stoi(std::to_string(arr[i]) + std::to_string(arr[j]));
      int temp2 = std::stoi(std::to_string(arr[j]) + std::to_string(arr[i]));
      if (temp % k == 0)
        count++;
      if(temp2 % k == 0)
        count++;
    }
  }

  std::cout << count;

}