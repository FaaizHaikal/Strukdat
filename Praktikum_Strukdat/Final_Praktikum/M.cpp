#include <bits/stdc++.h>

int main(){
  std::string s;
  std::cin >> s;
  std::stack<char> st;
  for (char c : s) {
    if (c == '(' || c == '{' || c == '[') {
        st.push(c);
    } else {
        if (st.empty() ||
            (c == ')' && st.top() != '(') || 
            (c == '}' && st.top() != '{') ||
            (c == ']' && st.top() != '[')) {
            std::cout << "unvaldi";
            return 0;
        }
        st.pop();
    }
  }

  if(st.empty()){
    std::cout << "valdi";
  } else {
    std::cout << "unvaldi";
  }
}