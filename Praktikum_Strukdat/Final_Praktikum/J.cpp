#include <bits/stdc++.h>

const int mod = 1e9 + 9;

long long solve(long long t) {
  long long base  = 2;
  long long power = t * (t-1)/2;
  long long ans = 1;
  while(power>0){
    if (power & 1) {
        ans = (ans * base) % mod;
    }
    base = (base * base) % mod;
    power /= 2;
  }
  return ans;
}

int main(){
  int n;
  std::cin >> n;
  long long t;
  while(n--){
    std::cin >> t;
    std::cout << "Zodiak found: " << solve(t) << " signs\n";
  }
}